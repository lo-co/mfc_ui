#ifndef ALICAT_H
#define ALICAT_H

#include <string>
#include <boost/preprocessor.hpp>
#include <memory>
#include <../serial/serialcomm.h>
#include <../data.h>

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
DEFINE_ENUM_WITH_STRING_CONVERSIONS(gas, (Air));

DEFINE_ENUM_WITH_STRING_CONVERSIONS(alicat_type, (M)(MC)(V)(VC)(P));



/**
* @brief Struct representing the data returned by an Alicat device.
* This struct represents all possible data that may be returned by an Alicat serial
* device.  Not all devices will utilize all parameters available.  For instance,
* the mass flow controller *will* use all while the mass flow meter will not utilize
* the setpoint.  Similarly, the volumetric flow meter will only utilize the volumetric
* flow field while the volumetric flow controller will utilize this value as well
* as the setpoint.
*/
struct alicat_data : Data {

    float pressure; /** Pressure in mb */
    float temperature; /** Temperature in degC */
    float flow_rate; /** Volumetric low rate; units are defined by the model */
    float mass_flow_rate; /** Mass flow rate; units are defined by the model */
    float setpoint; /** Device setpoint (if it is a controller); units are defined by the model */
    gas gas_; /** Enum as defined above representing the gas */

    alicat_data(float p = 0, float T = 0, float Q = 0,
                float Q0 = 0, float sp = 0, gas g = Air):pressure(p),
        temperature(T), flow_rate(Q), mass_flow_rate(Q0),
        setpoint(sp), gas_(g){
        setTime();
    }

};


/**
 * @brief Object representing an Alicat flow device.
 *
 */
class alicat
{
public:
    /**
     * @brief Constructor for an Alicat object.
     * @param addr Character representing the address of the Alicat device.  This value is A-Z.
     * @param id Unique string identifying the Alicat device.
     * @param port_ SerialComm object used for communicating with the Alicat device.
     */
    alicat(const char &addr, const std::string &id, std::shared_ptr<SerialComm> port_);

    /**
     * @brief Issues command for model information and processes it
     *
     * This method will send the command ``xM??`` and retrieve the data
     * that defines the model, make, range, etc of the controller or meter.
     */
    void get_model_information();

    Data get_data();




private:
    char address; /** Single ascii character (A-Z) representing the device address */
    std::string ID; /** Unique ID used to represent the device */
    bool is_controller; /** Boolean representing whether the device is a controller */
    std::string serial_number; /** Serial number of the device */
    int range; /** Range of controller. Units are dependent on the controller itself. */



    /**
     * @brief Parse string returned from read to fit Alicat Data format
     * Parse the string returned from a serial port read such that it fits
     * the Alicat data format provided by the struct ``alicat_data``.  This
     * will account for the model (i.e. type) of device that the port is
     * communicating with.
     *
     * @param msg String that is returned from a serial port read.
     *
     * @return Struct containing all of the data associated with the read
     * from the port that it is communicating on.  If the read is
     * unsuccessful, it will return an empty string.
     */
    alicat_data parse_data(const std::string &msg);

    std::shared_ptr<SerialComm> port; /** IOC for the serial port... */





};

#endif // ALICAT_H
