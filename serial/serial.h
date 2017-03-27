#ifndef SERIAL_H
#define SERIAL_H

#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/preprocessor.hpp>
#include <functional>

typedef std::function<void(std::string)> handler;

/* TODO - use a callback function that fires when a buffer is updated with data... */

class Serial
{
public:
    Serial(boost::asio::io_service& io_service, unsigned int baud, const std::string& device, handler handler_);
    void write(const char msg);
    void close();
    bool active();

private:
    static const int max_read_length = 512; // maximum amount of data to read in one operation
    bool active_; // remains true while this object is still operating
    boost::asio::io_service& io_service_; // the main IO service that runs this connection
    boost::asio::serial_port serialPort; // the serial port this instance is connected to
    char *read_msg_; // data read from the socket
    std::deque<char> write_msgs_; // buffered write data

    void read_start();
    void read_complete(const boost::system::error_code& error, size_t bytes_transferred);
    void do_write(const char msg);
    void write_start();
    void write_complete(const boost::system::error_code& error);
    void do_close(const boost::system::error_code& error);

    handler data_handler;
};

#endif // SERIAL_H
