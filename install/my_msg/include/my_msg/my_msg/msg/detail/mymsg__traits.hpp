// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

#ifndef MY_MSG__MSG__DETAIL__MYMSG__TRAITS_HPP_
#define MY_MSG__MSG__DETAIL__MYMSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_msg/msg/detail/mymsg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Mymsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: suijishu
  {
    out << "suijishu: ";
    rosidl_generator_traits::value_to_yaml(msg.suijishu, out);
    out << ", ";
  }

  // member: zhuanhuanzhi
  {
    out << "zhuanhuanzhi: ";
    rosidl_generator_traits::value_to_yaml(msg.zhuanhuanzhi, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mymsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: suijishu
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "suijishu: ";
    rosidl_generator_traits::value_to_yaml(msg.suijishu, out);
    out << "\n";
  }

  // member: zhuanhuanzhi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zhuanhuanzhi: ";
    rosidl_generator_traits::value_to_yaml(msg.zhuanhuanzhi, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mymsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_msg

namespace rosidl_generator_traits
{

[[deprecated("use my_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_msg::msg::Mymsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_msg::msg::Mymsg & msg)
{
  return my_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_msg::msg::Mymsg>()
{
  return "my_msg::msg::Mymsg";
}

template<>
inline const char * name<my_msg::msg::Mymsg>()
{
  return "my_msg/msg/Mymsg";
}

template<>
struct has_fixed_size<my_msg::msg::Mymsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_msg::msg::Mymsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_msg::msg::Mymsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MSG__MSG__DETAIL__MYMSG__TRAITS_HPP_
