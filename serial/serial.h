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

/* All of the above macros are used to convert strings returned from the
 * Alicat to an enum type defined in the macro invocation immediately
 * following.  This was taken from
 *
 * https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string#5094430
 *
 * It will be moved to wherever we need it.
 */
#define X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE(r, data, elem)    \
    case elem : return BOOST_PP_STRINGIZE(elem);

#define DEFINE_ENUM_WITH_STRING_CONVERSIONS(name, enumerators)                \
    enum name {                                                               \
        BOOST_PP_SEQ_ENUM(enumerators)                                        \
    };                                                                        \
                                                                              \
    inline const char* ToString(name v)                                       \
    {                                                                         \
        switch (v)                                                            \
        {                                                                     \
            BOOST_PP_SEQ_FOR_EACH(                                            \
                X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE,          \
                name,                                                         \
                enumerators                                                   \
            )                                                                 \
            default: return "[Unknown " BOOST_PP_STRINGIZE(name) "]";         \
        }                                                                     \
    }

/* Here is the enumeration for gas based on the preprocessor definition above */
DEFINE_ENUM_WITH_STRING_CONVERSIONS(gas, (Air))

/* This stuff is only here for testing right now...
 * move it when we have determined this will work.
 */
struct alicat_data{
    std::string address;
    float pressure;
    float temperature;
    float flow_rate;
    float mass_flow_rate;
    gas gas_;

};

class Serial
{
public:
    Serial(boost::asio::io_service& io_service, unsigned int baud, const std::string& device);
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
};

#endif // SERIAL_H
