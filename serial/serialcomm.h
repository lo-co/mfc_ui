#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <string>
#include <boost/asio.hpp>
#include <functional>

/** @brief Provides a structure for configuring the serial port */
struct serial_setup {



    boost::asio::serial_port_base::parity par;
    boost::asio::serial_port_base::character_size c_size;
    boost::asio::serial_port_base::flow_control flow;
    boost::asio::serial_port_base::stop_bits s_bits;
    std::string port;
    int baud;
    int timeout;
    /**
     * Constructor for flexible configuration of the serial port; this is an all or nothing
     * configuration.
     *
     * @param parity_ Parity of the serial connection.  Default is none.
     * @param c_size_ Size of the data packet.  Default is 8 bits.
     * @param flow_ Flow control.  Default is none.
     * @param stop_bits Stop bits.  Default is one
     * @param port_ String representation for the location of the port.  Default is "/dev/ttyUSB0".
     * @param baud_rate_ Communication baud rate on serial port.  Default is 19.2 kbits/s
     * @param timeout Timeout for communicating on port.  Default is 1 s.
     *
     * @see boost::asio::serial_port_base
     */
    serial_setup(boost::asio::serial_port_base::parity parity_= boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none),
                 boost::asio::serial_port_base::character_size c_size_ = boost::asio::serial_port_base::character_size(8),
                 boost::asio::serial_port_base::flow_control flow_ = boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none),
                 boost::asio::serial_port_base::stop_bits stop_bits = boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one),
                 std::string port_ = "/dev/ttyUSB0",
                 int baud_rate_ = 19200,
                 int timeout = 1000):par(parity_), c_size(c_size_), flow(flow_),
        s_bits(stop_bits), port(port_), baud(baud_rate_), timeout(timeout){}

    // Default setup for 19200, 8-N-1, no flow
    serial_setup(std::string port_):par(boost::asio::serial_port_base::parity::none),
        c_size(boost::asio::serial_port_base::character_size(8)),flow(boost::asio::serial_port_base::flow_control::none),
        s_bits(boost::asio::serial_port_base::stop_bits::one), port(port_), baud(19200), timeout(1000){}


    serial_setup(std::string port_, int baud_):par(boost::asio::serial_port_base::parity::none),
        c_size(boost::asio::serial_port_base::character_size(8)),flow(boost::asio::serial_port_base::flow_control::none),
        s_bits(boost::asio::serial_port_base::stop_bits::one), port(port_), baud(baud_), timeout(1000){}


};


/** Provides a structure for communication on the serial port. */
struct io_parameters{

    std::string delim;
    bool fixed_size;
    char* data;
    size_t size;

    io_parameters(): delim(""), fixed_size(false), data(0), size(0) {}

    // Setup with just the delimiter
    io_parameters(const std::string &delim_): delim(delim_), fixed_size(false), data(0), size(0) {}

    // Provide a place for the data and the amount to read
    io_parameters(char *data, size_t size): delim(""), fixed_size(true),data(data), size(size) { }



};

/*! Function typedef for handling the case where serial port reading is complete. */
typedef std::function<void(std::string)> handler;

/** Enum for defining the current wait state of the serial port read */
enum waitResult {
    in_progress, /** Port is currently busy with a read. */
    success, /** Read has returned without error */
    error_out, /** Error detected on port */
    timeout_expired, /** No error detected but timer has expired */
    op_canceled,
    port_cancelled
};

/**
 * @brief Class that wraps serial port communication.
 *
 */
class SerialComm
{
public:

    SerialComm();
    SerialComm(const io_parameters& io, const serial_setup& serial, handler handler_);

    /**
     * @brief Write a string to the port.
     *
     * Calls the write function in basic_serial_port, creating a buffer from the string
     * provided to write to the port
     *
     * @param s String to write to the port.
     *
     * @see boost::asio::serial_port::write
     *
     */
    void writeString(const std::string& s);

    /**
     * @brief Read from serial port until delimiter reached.
     *
     * This function will set a timer which will expire at the time defined by
     * port_params.timeout.  Whilst the timer is operational, it will also
     * perform an async_read_until.  If the timer expires, then the read will be
     * canceled.  If the read is successful before the timer expires, the timer
     * will be canceled and the read will be handled by the handler provided by
     * the caller.
     *
     * @see boost::asio::serial_port::async_read_until
     * @see boost::async_wait
     */
    std::string readStrUntil();

    /**
     * @brief Closes the serial port.
     *
     * @see boost::asio::serial_port::close
     */
    void close();


private:
    io_parameters io_params;  /** Parameters used for communicating with current port */
    serial_setup port_params; /** Parameters used to setup communication with the current port */
    boost::asio::io_service io_service_;

    boost::asio::serial_port port;
    boost::asio::streambuf readData;

    handler data_handler; /** Handler that will be to handle the data on a successful read */

    /**
     * @brief Handler that is called by the read function.
     * @param error
     * @param bytesTransferred
     */
    void readCompleted(const boost::system::error_code& error,
                       const size_t bytesTransferred);

    /**
     * @brief Handler for async_wait function
     * @param error
     */
    void timeoutExpired(const boost::system::error_code& error);

    waitResult wait_result;

    size_t bytes_transferred;

    boost::asio::deadline_timer timer;

};

#endif // SERIALCOMM_H
