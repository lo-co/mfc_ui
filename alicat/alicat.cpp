#include "alicat.h"
#include <boost/tokenizer.hpp>

alicat::alicat(std::string addr, std::string id): address(addr), ID(id)
{

}
alicat_data *alicat::parse_data(const std::string &dataIn){

    alicat_data *ac;

    ac->flow_rate = 0;
    ac->gas_ = Air;
    ac->mass_flow_rate = 0;
    ac->temperature = 0;
    ac->pressure = 0;
    ac->setpoint = 0;

    boost::char_separator<char> sep(" ");
    boost::tokenizer<boost::char_separator<char>> tok(dataIn, sep);

    /*for(boost::tokenizer<boost::char_separator<char>>::iterator beg=tok.begin(); beg!=tok.end();++beg){
        cout << *beg << "\n";
    }*/


    return ac;
}

void alicat::get_model_information(){


}
