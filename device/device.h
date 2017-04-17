/**
 * @file device.h
 * @author M. Richardson
 * @copyright (2017) NOAA
 *
 */

#ifndef DEVICE
#define DEVICE

#include "../data.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

/**
 * @brief Abstract object defining some basic device functionality.
 */
class Device{

public:

    Device(std::string id): dev_id(id){}

    /**
     * @brief Retrieve standard data associated with this device
     * @return data object encapsulating the data defined by this implementation
     */
    virtual Data* get_data() = 0;

    /**
     * @brief Read in data specific to the device implementation from the configuration file.
     * @param pt Property tree present in the configuration file used.
     */
    virtual void configure_device(boost::property_tree::ptree pt)=0;

protected:
    std::string dev_id;
    std::string serial_number;
};

#endif // DEVICE

