// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

#ifndef MY_MSG__MSG__DETAIL__MYMSG__BUILDER_HPP_
#define MY_MSG__MSG__DETAIL__MYMSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_msg/msg/detail/mymsg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_msg
{

namespace msg
{

namespace builder
{

class Init_Mymsg_zhuanhuanzhi
{
public:
  explicit Init_Mymsg_zhuanhuanzhi(::my_msg::msg::Mymsg & msg)
  : msg_(msg)
  {}
  ::my_msg::msg::Mymsg zhuanhuanzhi(::my_msg::msg::Mymsg::_zhuanhuanzhi_type arg)
  {
    msg_.zhuanhuanzhi = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_msg::msg::Mymsg msg_;
};

class Init_Mymsg_suijishu
{
public:
  Init_Mymsg_suijishu()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mymsg_zhuanhuanzhi suijishu(::my_msg::msg::Mymsg::_suijishu_type arg)
  {
    msg_.suijishu = std::move(arg);
    return Init_Mymsg_zhuanhuanzhi(msg_);
  }

private:
  ::my_msg::msg::Mymsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_msg::msg::Mymsg>()
{
  return my_msg::msg::builder::Init_Mymsg_suijishu();
}

}  // namespace my_msg

#endif  // MY_MSG__MSG__DETAIL__MYMSG__BUILDER_HPP_
