// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

#ifndef MY_MSG__MSG__DETAIL__MYMSG__FUNCTIONS_H_
#define MY_MSG__MSG__DETAIL__MYMSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "my_msg/msg/rosidl_generator_c__visibility_control.h"

#include "my_msg/msg/detail/mymsg__struct.h"

/// Initialize msg/Mymsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_msg__msg__Mymsg
 * )) before or use
 * my_msg__msg__Mymsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
bool
my_msg__msg__Mymsg__init(my_msg__msg__Mymsg * msg);

/// Finalize msg/Mymsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
void
my_msg__msg__Mymsg__fini(my_msg__msg__Mymsg * msg);

/// Create msg/Mymsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_msg__msg__Mymsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
my_msg__msg__Mymsg *
my_msg__msg__Mymsg__create();

/// Destroy msg/Mymsg message.
/**
 * It calls
 * my_msg__msg__Mymsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
void
my_msg__msg__Mymsg__destroy(my_msg__msg__Mymsg * msg);

/// Check for msg/Mymsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
bool
my_msg__msg__Mymsg__are_equal(const my_msg__msg__Mymsg * lhs, const my_msg__msg__Mymsg * rhs);

/// Copy a msg/Mymsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
bool
my_msg__msg__Mymsg__copy(
  const my_msg__msg__Mymsg * input,
  my_msg__msg__Mymsg * output);

/// Initialize array of msg/Mymsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_msg__msg__Mymsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
bool
my_msg__msg__Mymsg__Sequence__init(my_msg__msg__Mymsg__Sequence * array, size_t size);

/// Finalize array of msg/Mymsg messages.
/**
 * It calls
 * my_msg__msg__Mymsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
void
my_msg__msg__Mymsg__Sequence__fini(my_msg__msg__Mymsg__Sequence * array);

/// Create array of msg/Mymsg messages.
/**
 * It allocates the memory for the array and calls
 * my_msg__msg__Mymsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
my_msg__msg__Mymsg__Sequence *
my_msg__msg__Mymsg__Sequence__create(size_t size);

/// Destroy array of msg/Mymsg messages.
/**
 * It calls
 * my_msg__msg__Mymsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
void
my_msg__msg__Mymsg__Sequence__destroy(my_msg__msg__Mymsg__Sequence * array);

/// Check for msg/Mymsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
bool
my_msg__msg__Mymsg__Sequence__are_equal(const my_msg__msg__Mymsg__Sequence * lhs, const my_msg__msg__Mymsg__Sequence * rhs);

/// Copy an array of msg/Mymsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_msg
bool
my_msg__msg__Mymsg__Sequence__copy(
  const my_msg__msg__Mymsg__Sequence * input,
  my_msg__msg__Mymsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MY_MSG__MSG__DETAIL__MYMSG__FUNCTIONS_H_
