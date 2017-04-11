#include "alicat.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

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

            ac = alicat_data(std::stof(tokens.at(1)),
                             std::stof(tokens.at(2)),
                             std::stof(tokens.at(3)),
                             std::stof(tokens.at(4)),
                             std::stof(tokens.at(5)),
                             Air);
        }
        catch(std::exception const &e){
            cout << msg <<endl;
            cout << "Exception thrown in simple_test.  EC: "  + string(e.what(), 100)<<endl;
        }
    }


    return ac;
}

void alicat::get_model_information(){


}

void alicat::set_gas(gas g){
    port->writeString(string(&address) + "$$" + to_string((int)g));
}

Data alicat::get_data(){

    alicat_data ac_data = {0, 0, 0, 0, 0, Air};
    //parse_data(port->async_rw(std::string(&address) + "\r"));

    return (Data) ac_data;

}
