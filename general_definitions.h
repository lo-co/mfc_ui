/**
 * @file general_definitions.h
 * @author M. Richardson
 * @copyright (2017) NOAA
 * @version 0.0.1
 */

#ifndef GENERAL_DEFINITIONS
#define GENERAL_DEFINITIONS

#endif // GENERAL_DEFINITIONS

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



/**
 * @brief Preprocessor directive for defining enums with string conversions.
 * This directive allows the conversion of a string to an enumeration value.
 */
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
