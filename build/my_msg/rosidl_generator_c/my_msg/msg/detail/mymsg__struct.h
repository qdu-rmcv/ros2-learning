// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

#ifndef MY_MSG__MSG__DETAIL__MYMSG__STRUCT_H_
#define MY_MSG__MSG__DETAIL__MYMSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Mymsg in the package my_msg.
typedef struct my_msg__msg__Mymsg
{
  /// british节点发布随机整数值的消息接口
  int32_t suijishu;
  /// metric节点转换与发布浮点数的消息接口
  float zhuanhuanzhi;
} my_msg__msg__Mymsg;

// Struct for a sequence of my_msg__msg__Mymsg.
typedef struct my_msg__msg__Mymsg__Sequence
{
  my_msg__msg__Mymsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_msg__msg__Mymsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MSG__MSG__DETAIL__MYMSG__STRUCT_H_
