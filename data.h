#ifndef DATA
#define DATA

#include <boost/date_time.hpp>


/**
 * @brief Container for data returned from measurement devices.
 */
struct Data{

    boost::posix_time::ptime mTime; /** Time of the measurement. */

    /**
     * @brief Set the current measurement.
     *
     * @see boost::posix_time::second_clock::local_time()
     */
    void setTime(){mTime = boost::posix_time::second_clock::local_time();}


};

#endif // DATA

