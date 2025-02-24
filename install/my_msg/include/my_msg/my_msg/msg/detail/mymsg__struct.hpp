// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

#ifndef MY_MSG__MSG__DETAIL__MYMSG__STRUCT_HPP_
#define MY_MSG__MSG__DETAIL__MYMSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_msg__msg__Mymsg __attribute__((deprecated))
#else
# define DEPRECATED__my_msg__msg__Mymsg __declspec(deprecated)
#endif

namespace my_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Mymsg_
{
  using Type = Mymsg_<ContainerAllocator>;

  explicit Mymsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->suijishu = 0l;
      this->zhuanhuanzhi = 0.0f;
    }
  }

  explicit Mymsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->suijishu = 0l;
      this->zhuanhuanzhi = 0.0f;
    }
  }

  // field types and members
  using _suijishu_type =
    int32_t;
  _suijishu_type suijishu;
  using _zhuanhuanzhi_type =
    float;
  _zhuanhuanzhi_type zhuanhuanzhi;

  // setters for named parameter idiom
  Type & set__suijishu(
    const int32_t & _arg)
  {
    this->suijishu = _arg;
    return *this;
  }
  Type & set__zhuanhuanzhi(
    const float & _arg)
  {
    this->zhuanhuanzhi = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_msg::msg::Mymsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_msg::msg::Mymsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_msg::msg::Mymsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_msg::msg::Mymsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_msg::msg::Mymsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_msg::msg::Mymsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_msg::msg::Mymsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_msg::msg::Mymsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_msg::msg::Mymsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_msg::msg::Mymsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_msg__msg__Mymsg
    std::shared_ptr<my_msg::msg::Mymsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_msg__msg__Mymsg
    std::shared_ptr<my_msg::msg::Mymsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mymsg_ & other) const
  {
    if (this->suijishu != other.suijishu) {
      return false;
    }
    if (this->zhuanhuanzhi != other.zhuanhuanzhi) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mymsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mymsg_

// alias to use template instance with default allocator
using Mymsg =
  my_msg::msg::Mymsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_msg

#endif  // MY_MSG__MSG__DETAIL__MYMSG__STRUCT_HPP_
