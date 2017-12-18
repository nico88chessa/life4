#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <type_traits>

template <typename T> struct isFloat { static constexpr bool value = false; };
template <> struct isFloat<float> { static constexpr bool value = true; };

template <typename T> struct isDouble { static constexpr bool value = false; };
template <> struct isDouble<double> { static constexpr bool value = true; };

/* enum declaration */

#define DECL_ENUM_VALUE(ITEM) ITEM
#define DECL_ENUM_VALUE_STR(ITEM) #ITEM

#define DECL_ENUM_TYPE(TYPE, LIST) \
    enum struct TYPE : int { LIST(DECL_ENUM_VALUE) };

#define DECL_ENUM_TYPE_STR(TYPE, LIST) \
    static const char* TYPE##Str[] = { LIST(DECL_ENUM_VALUE_STR) };

#define DECL_ENUM_TYPE_SIZE(TYPE) \
    static constexpr int TYPE##Size = std::extent<decltype(TYPE##Str)>::value;

#define DECL_ENUM_TYPE_FROM_STR(TYPE)                           \
    static inline int TYPE##FromString(const char* str) {       \
        for (int i=0; i<TYPE##Size; i++)                        \
            if (std::string(TYPE##Str[i]).compare(str) == 0)    \
                return i;                                       \
        return -1;                                              \
    }

#define DECL_ENUMS(NAME, LIST)          \
    DECL_ENUM_TYPE(NAME, LIST)          \
    DECL_ENUM_TYPE_STR(NAME, LIST)      \
    DECL_ENUM_TYPE_SIZE(NAME)           \
    DECL_ENUM_TYPE_FROM_STR(NAME)


/* example enum Test 2 with 3 items
 *
 * #define DECL_ENUM_LIST(ITEM) \
 *     ITEM(Uno), \
 *     ITEM(Due), \
 *     ITEM(Tre)
 * DECL_ENUMS(Test2, LIST)
 *
 */

#endif
