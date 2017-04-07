#include "serialcomm.h"
#include <boost/bind.hpp>
#include <iostream>
#include <boost/date_time.hpp>
#include <boost/timer.hpp>
#include <boost/algorithm/string/trim.hpp>

#include <fstream>


#define BOOST_ASIO_ENABLE_HANDLER_TRACKING

using namespace boost::asio;
using namespace std;

ofstream test_file;

boost::timer* timer_ = new boost::timer();
size_t n_handlers;
int index_ = 0;

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

    test_file.open("/home/mrichardson/record_data.txt");



}


void SerialComm::writeString(const string &s){
    write(port, buffer(s.c_str(), s.size()));
}


std::string SerialComm::readStrUntil(){

    //++index_;

    string data_out = "";

    // Set up two things here - timer for waiting and a async_read to read
    // If async_read returns first - success! Else, something happened
    if (io_params.delim != ""){

        cout << "Starting read..." << endl;

        //Set up for wait and read.
        wait_result = in_progress;

        try{
            async_read_until(port,readData,io_params.delim,
                             boost::bind(&SerialComm::readCompleted,
                                         this,boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));



            //timer_->restart();
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
            n_handlers = io_service_.run_one();


            // Brackets in success case limit scope of new variables
            switch(wait_result){
            case success:{

                char c_[1024];
                //string msg;
                string delims = "\r";

                std::string msg{buffers_begin(readData.data()), buffers_begin(readData.data()) + bytes_transferred- delims.size()};
                // Consume through the first delimiter.
                readData.consume(bytes_transferred);

                /*istream is(&readData);
                cout<< is.gcount() << " characters in the stream..." << endl;
                is.getline(c_, bytes_transferred, '\r');
                // Remove the delimiter byte - don't want this.
                bytes_transferred -= 1;
                msg = string(c_, 48);
                //getline(is, msg, '\r');
                boost::trim_if(msg, boost::is_any_of("\r"));*/

                //test_file << hex << (int)c_ << endl;

                /*if (msg[0] == ""){
                    cout << "whoops" << endl;
                }*/

                //if (msg == "")

                /*istream is(&readData);

                // Allocation of string
                string msg(bytes_transferred, '\0');

                is.read(&msg[0], bytes_transferred);


                // Remove the delimiter
                is.ignore(1);
                */

                data_out = msg;
                cout << msg << endl;

                data_handler(msg);

                return data_out;

            }

            case timeout_expired:

                //Set up for wait and read.
                wait_result = in_progress;


                /*async_read_until(port,readData,io_params.delim,
                                 boost::bind(&SerialComm::readCompleted,
                                             this,boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));

                timer.expires_from_now(boost::posix_time::seconds(1));
                timer.async_wait(boost::bind(&SerialComm::timeoutExpired,this,
                                             boost::asio::placeholders::error));
                                             */
                cout << "Time is up..." << endl;
                return data_out;
                break ;
            case error_out:
                cout << "Error out..." << endl;
                return data_out;
                break ;
            case op_canceled:
                return data_out;
                break;

            case in_progress:
                cout << "In progress..." << endl;
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

    //cout << to_string(timer_->elapsed()) << endl;
    if (!error && wait_result == in_progress) {
        wait_result = timeout_expired;
        cout << "Timed out..." <<endl;

        try{
            port.cancel();
        }
        catch(std::exception const &e){
            cout << "tried to cancel read on port but got error..." <<endl;
        }

    }
    else {
        if (error.value() != 125) {wait_result = error_out;

            cout << "Timer canceled.  Error was " + to_string(error.value())<<endl;
        }
        else {
            wait_result =  op_canceled;

            cout << "Timer canceled.  Error was " + to_string(error.value())<<endl;

        }
    }


}

void SerialComm::close(){
    port.close();
    test_file.close();
    
}
