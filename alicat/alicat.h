#ifndef ALICAT_H
#define ALICAT_H

#include <string>
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

typedef struct alicat_data {
    float pressure;
    float temperature;
    float flow_rate;
    float mass_flow_rate;
    float setpoint;
    gas gas_;

    alicat_data(float p = 0, float T = 0, float Q = 0,
                float Q0 = 0, float sp = 0, gas g = Air):pressure(p),
                temperature(T), flow_rate(Q), mass_flow_rate(Q0),
                setpoint(sp), gas_(g){}

} alicat_data;

class alicat
{
public:
    alicat(std::string addr, std::string id);

    alicat_data *parse_data(const std::string &dataIn);


private:
    std::string address;
    std::string ID;

};

#endif // ALICAT_H
