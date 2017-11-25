#ifndef UTILITY_HPP
#define UTILITY_HPP

template <typename T> struct isFloat { static constexpr bool value = false; };
template <> struct isFloat<float> { static constexpr bool value = true; };

template <typename T> struct isDouble { static constexpr bool value = false; };
template <> struct isDouble<double> { static constexpr bool value = true; };

#endif
