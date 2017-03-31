#include "serialcomm.h"
#include <boost/bind.hpp>
#include <iostream>

using namespace boost::asio;
using namespace std;

SerialComm::SerialComm(io_parameters io,  serial_setup serial, handler handler_):
    io_params(io),port_params(serial),
    io_service_(), port(io_service_, port_params.port), data_handler(handler_)
{

    port.set_option(serial_port_base::baud_rate(port_params.baud));
    port.set_option(port_params.par);
    port.set_option(port_params.c_size);
    port.set_option(port_params.flow);
    port.set_option(port_params.s_bits);

}


void SerialComm::writeString(const string &s){
    write(port, buffer(s.c_str(), s.size()));
}


void SerialComm::readStrUntil(){

    boost::asio::streambuf readData;
    string data_out = "";

    deadline_timer  timer(io_service_, boost::posix_time::milliseconds(port_params.timeout));

    // Set up two things here - timer for waiting and a async_read to read
    // If async_read returns first - success! Else, something happened
    if (io_params.delim != ""){

        //Set up for wait and read.
        wait_result = in_progress;

        timer.async_wait(boost::bind(&SerialComm::timeoutExpired,this,
                                     boost::asio::placeholders::error));

        async_read_until(port,readData,io_params.delim,
                         boost::bind(&SerialComm::readCompleted,
                                     this,boost::asio::placeholders::error,
                                     boost::asio::placeholders::bytes_transferred));


        // This blocks until an event on io_service_ is set.

        io_service_.run_one();


        // Brackets in success case limit scope of new variables
        switch(wait_result){
        case success:{
            timer.cancel();
            // Remove the delimiter byte - don't want this.
            bytes_transferred -= 1;
            istream is(&readData);
            // Allocation of string
            string msg(bytes_transferred, '\0');

            is.read(&msg[0], bytes_transferred);
            // Remove the delimiter
            is.ignore(1);
            data_handler(msg);
            break ;}
        case timeout_expired:
            cout << "Time is up..." << endl;
            break ;
        case error_out:
            cout << "Serial port error read..." << endl;
            break ;
        case in_progress:
            break;
        }

    }
}


void SerialComm::readCompleted(const boost::system::error_code& error,
                               const size_t bytesTransferred){
    if (!error){
        wait_result = success;
        bytes_transferred = bytesTransferred;
    }
    else {wait_result = error_out;}

}

void SerialComm::timeoutExpired(const boost::system::error_code &error){
    if (!error && wait_result == in_progress){wait_result = timeout_expired;}

}

void SerialComm::close(){
    port.close();
}
