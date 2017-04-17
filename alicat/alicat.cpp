#include "alicat.h"
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/find.hpp>


using namespace std;

alicat::alicat(const char &addr, const std::string &id, std::shared_ptr<SerialComm> port_):
    address(addr), port(port_), Device(id)
{

}

/** @todo Make this routine dependent on the model of the alicat. */
alicat_data alicat::parse_data(const std::string &msg){

    alicat_data ac = {0,0,0,0,0,Air};


    // If the first character is not printable, don't try to parse it.
    if(isprint(msg[0])){
        try{
            std::vector<string> tokens;
            boost::split(tokens, msg, boost::is_any_of(" "));

            alicat_data *ac_ = new alicat_data(stof(tokens.at(1)), stof(tokens.at(2)),
                                               stof(tokens.at(3)),stof(tokens.at(4)),
                                               stof(tokens.at(5)), Air);

            ac = *ac_;
        }
        catch(std::exception const &e){
            cout << msg <<endl;
            cout << "Exception thrown in simple_test.  EC: "  + string(e.what(), 100)<<endl;
        }
    }

    return ac;
}

void alicat::get_model_information(){

    string model_data = port->async_rw(string(&address) + "??M*");
    string line; // Inidividual lines of test in the model_data string

    stringstream ss(model_data);

    while(std::getline(ss, line)){

        // Search each line for the Model or Mdl key-word
        if (boost::find_first(line, "Model") || boost::find_first(line, "Mdl")){

            // Break the line up into tokens delimited by spaces
            std::vector<string> tokens;
            boost::split(tokens, line, boost::is_any_of(" "));

            // Subtokens break up the token into bits if a hyphen is detected...
            std::vector<string> subtokens;

            for (auto const& token: tokens){
                boost::split(subtokens, token, boost::is_any_of("-"));

                /* The model definition looks something like MC-100SCCM-D
                 * Hyphen found if more than one token.  Tokens defined as:
                 *   * Type - MC, M, VC, V, PC, V where the C defines the type as controller
                 *   * Range + units
                 *   * Not sure what this is.
                 */
                if (subtokens.size() > 1){
                    for (auto const&stoken: subtokens){

                        cout << stoken <<endl;
                    }
                    break;
                }



            }
        }
    }
}

void alicat::set_gas(gas g){
    port->writeString(string(&address) + "$$" + to_string((int)g));
}

Data *alicat::get_data(){

    alicat_data* ac_data = new alicat_data(0, 0, 0, 0, 0, Air);

    alicat_data addr_data = parse_data(port->async_rw(string(1, address)));

    ac_data = &addr_data;

    return (Data*) ac_data;

}

void alicat::configure_device(boost::property_tree::ptree pt){

    if (!port->isOpen()){
        port->open(pt.get<std::string>("Alicat.Port"));
    }

    address = pt.get<char>( "Alicat." + dev_id + "_Address");

    set_flow_rate(pt.get<float>("Alicat." + dev_id + "_Q0"));

    get_model_information();

}

void alicat::set_flow_rate(float q){

    port->async_rw(string(1, address) + to_string(int(q*64000/max_flow)));
}

alicat::~alicat(){
    cout << "Alicat with ID " + dev_id + " closed." << endl;
}
