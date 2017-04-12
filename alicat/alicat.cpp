#include "alicat.h"
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/find.hpp>


using namespace std;

alicat::alicat(const char &addr, const std::string &id, std::shared_ptr<SerialComm> port_):
    address(addr), ID(id), port(port_)
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

    //boost::iterator_range<string> model_range;

    while(std::getline(ss, line)){
        if (boost::find_first(line, "Model") || boost::find_first(line, "Mdl")){

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

alicat::~alicat(){
    cout << "Alicat with ID " + ID + " closed." << endl;
}
