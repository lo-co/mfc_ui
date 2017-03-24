#include "serial.h"
#include <boost/tokenizer.hpp>

using namespace std;

Serial::Serial(boost::asio::io_service& io_service, unsigned int baud, const string& device)
    : active_(true),
      io_service_(io_service),
      serialPort(io_service, device),
      read_msg_(new char[max_read_length])
{
    if (not serialPort.is_open())
    {
        cerr << "Failed to open serial port\n";
        return;
    }
    boost::asio::serial_port_base::baud_rate baud_option(baud);
    serialPort.set_option(baud_option); // set the baud rate after the port has been opened
    read_start();
}


void Serial::write(const char msg) // pass the write data to the do_write function via the io service in the other thread
{
    io_service_.post(boost::bind(&Serial::do_write, this, msg));
}

void Serial::close() // call the do_close function via the io service in the other thread
{
    io_service_.post(boost::bind(&Serial::do_close, this, boost::system::error_code()));
}

bool Serial::active() // return true if the socket is still active
{
    return active_;
}

void Serial::read_start()
{ // Start an asynchronous read and call read_complete when it completes or fails
    serialPort.async_read_some(boost::asio::buffer(read_msg_, max_read_length),
                               boost::bind(&Serial::read_complete,
                                           this,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred));
}

void Serial::read_complete(const boost::system::error_code& error, size_t bytes_transferred)
{ // the asynchronous read operation has now completed or failed and returned an error
    if (!error)
    { // read completed, so process the data
        //cout << "here i am" << endl;

        string str_msg = string(read_msg_);
        cout <<'\r' << str_msg << flush;
        boost::char_separator<char> sep(" ");
        boost::tokenizer<boost::char_separator<char>> tok(str_msg, sep);

        /*for(boost::tokenizer<boost::char_separator<char>>::iterator beg=tok.begin(); beg!=tok.end();++beg){
            cout << *beg << "\n";
        }*/
        //cout.write(read_msg_, bytes_transferred); // echo to standard output
        read_start(); // start waiting for another asynchronous read again
    }
    else
        do_close(error);
}

void Serial::do_write(const char msg)
{ // callback to handle write call from outside this class
    bool write_in_progress = !write_msgs_.empty(); // is there anything currently being written?
    write_msgs_.push_back(msg); // store in write buffer
    if (!write_in_progress) // if nothing is currently being written, then start
        write_start();
}

void Serial::write_start()
{ // Start an asynchronous write and call write_complete when it completes or fails
    boost::asio::async_write(serialPort,
                             boost::asio::buffer(&write_msgs_.front(), 1),
                             boost::bind(&Serial::write_complete,
                                         this,
                                         boost::asio::placeholders::error));
}

void Serial::write_complete(const boost::system::error_code& error)
{ // the asynchronous read operation has now completed or failed and returned an error
    if (!error)
    { // write completed, so send next write data
        write_msgs_.pop_front(); // remove the completed data
        if (!write_msgs_.empty()) // if there is anthing left to be written
            write_start(); // then start sending the next item in the buffer
    }
    else
        do_close(error);
}

void Serial::do_close(const boost::system::error_code& error)
{ // something has gone wrong, so close the socket & make this object inactive
    if (error == boost::asio::error::operation_aborted) // if this call is the result of a timer cancel()
        return; // ignore it because the connection cancelled the timer
    if (error)
        cerr << "Error: " << error.message() << endl; // show the error message
    else
        cout << "Error: Connection did not succeed.\n";
    cout << "Press Enter to exit\n";
    serialPort.close();
    active_ = false;
}
