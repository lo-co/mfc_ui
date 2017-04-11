#include "serialcomm.h"
#include <boost/bind.hpp>
#include <iostream>
#include <boost/date_time.hpp>
#include <boost/timer.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace boost::asio;
using namespace std;

SerialComm::SerialComm(const io_parameters& io, const  serial_setup& serial, handler handler_):
    io_params(io)
  ,port_params(serial)
  ,io_service_()
  ,port(io_service_)
  ,data_handler(handler_)
  ,timer(io_service_)
{

    port.open(port_params.port);

    port.set_option(serial_port_base::baud_rate(port_params.baud));
    port.set_option(port_params.par);
    port.set_option(port_params.c_size);
    port.set_option(port_params.flow);
    port.set_option(port_params.s_bits);

}


void SerialComm::writeString(const string &s){

    string delim_str = s;

    // Add the delimiter if there is one specified
    if (io_params.delim != "") delim_str = s + io_params.delim;

    write(port, buffer(s.c_str(), s.size()));
}

std::string SerialComm::async_rw(std::string w_str, bool multiline){

    writeString(w_str);
    string r_string =readStrUntil();

    if (multiline) {while (r_string != (r_string += readStrUntil())){}}

    return r_string;
}

std::string SerialComm::readStrUntil(){

    string data_out = "";

    // Set up two things here - timer for waiting and a async_read to read
    // If async_read returns first - success! Else, something happened
    if (io_params.delim != ""){

        //Set up for wait and read.
        wait_result = in_progress;

        try{
            async_read_until(port,readData,io_params.delim,
                             boost::bind(&SerialComm::readCompleted,
                                         this,boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));

            timer.expires_from_now(boost::posix_time::seconds(1));
            timer.async_wait(boost::bind(&SerialComm::timeoutExpired,this,
                                         boost::asio::placeholders::error));

        }
        catch(std::exception const &e){
            cout << "Exception thrown in while starting async services.  EC: "  + string(e.what(), 100)<<endl;
        }

        // The loop is required in the case where events are thrown that are
        // related to canceling operations.
        for (;;){

            // This blocks until an event on io_service_ is set.
            io_service_.run_one();

            // Brackets in success case limit scope of new variables
            switch(wait_result){
            case success:{

                std::string msg{buffers_begin(readData.data()),
                            buffers_begin(readData.data()) + bytes_transferred- io_params.delim.size()};

                // Consume through the first delimiter.
                readData.consume(bytes_transferred);

                data_handler(msg);

                return data_out;

            }
            case timeout_expired:
                return "";
            case error_out:
            case op_canceled:
            case in_progress:
            case port_cancelled:
                break;
            }

        }
    }

    return data_out;
}

void SerialComm::readCompleted(const boost::system::error_code& error,
                               const size_t bytesTransferred){
    if (!error){
        wait_result = success;
        bytes_transferred = bytesTransferred;
    }
    else {
        if (error.value() != 125) wait_result = error_out;
        else wait_result = op_canceled;

        cout << "Port handler called with error code " + to_string(error.value()) << endl;
    }

}

void SerialComm::timeoutExpired(const boost::system::error_code &error){

    if (!error) {
        wait_result = timeout_expired;
        cout << "Timeout..." << endl;

        try{
            port.cancel();
        }
        catch(std::exception const &e){
            cout << "tried to cancel read on port but got error..." <<endl;
        }

    }
    else {
        if (error.value() != 125) {

            wait_result = error_out;

            cout << "Timer canceled.  Error was " + to_string(error.value())<<endl;
        }
        else {
            wait_result =  op_canceled;


        }
    }


}

void SerialComm::close(){
    port.close();
    test_file.close();
    
}
