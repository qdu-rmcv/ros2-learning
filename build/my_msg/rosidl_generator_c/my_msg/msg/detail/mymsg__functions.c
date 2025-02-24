// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice
#include "my_msg/msg/detail/mymsg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_msg__msg__Mymsg__init(my_msg__msg__Mymsg * msg)
{
  if (!msg) {
    return false;
  }
  // suijishu
  // zhuanhuanzhi
  return true;
}

void
my_msg__msg__Mymsg__fini(my_msg__msg__Mymsg * msg)
{
  if (!msg) {
    return;
  }
  // suijishu
  // zhuanhuanzhi
}

bool
my_msg__msg__Mymsg__are_equal(const my_msg__msg__Mymsg * lhs, const my_msg__msg__Mymsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // suijishu
  if (lhs->suijishu != rhs->suijishu) {
    return false;
  }
  // zhuanhuanzhi
  if (lhs->zhuanhuanzhi != rhs->zhuanhuanzhi) {
    return false;
  }
  return true;
}

bool
my_msg__msg__Mymsg__copy(
  const my_msg__msg__Mymsg * input,
  my_msg__msg__Mymsg * output)
{
  if (!input || !output) {
    return false;
  }
  // suijishu
  output->suijishu = input->suijishu;
  // zhuanhuanzhi
  output->zhuanhuanzhi = input->zhuanhuanzhi;
  return true;
}

my_msg__msg__Mymsg *
my_msg__msg__Mymsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msg__msg__Mymsg * msg = (my_msg__msg__Mymsg *)allocator.allocate(sizeof(my_msg__msg__Mymsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_msg__msg__Mymsg));
  bool success = my_msg__msg__Mymsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_msg__msg__Mymsg__destroy(my_msg__msg__Mymsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_msg__msg__Mymsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_msg__msg__Mymsg__Sequence__init(my_msg__msg__Mymsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msg__msg__Mymsg * data = NULL;

  if (size) {
    data = (my_msg__msg__Mymsg *)allocator.zero_allocate(size, sizeof(my_msg__msg__Mymsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_msg__msg__Mymsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_msg__msg__Mymsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_msg__msg__Mymsg__Sequence__fini(my_msg__msg__Mymsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_msg__msg__Mymsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_msg__msg__Mymsg__Sequence *
my_msg__msg__Mymsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msg__msg__Mymsg__Sequence * array = (my_msg__msg__Mymsg__Sequence *)allocator.allocate(sizeof(my_msg__msg__Mymsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_msg__msg__Mymsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_msg__msg__Mymsg__Sequence__destroy(my_msg__msg__Mymsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_msg__msg__Mymsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_msg__msg__Mymsg__Sequence__are_equal(const my_msg__msg__Mymsg__Sequence * lhs, const my_msg__msg__Mymsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_msg__msg__Mymsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_msg__msg__Mymsg__Sequence__copy(
  const my_msg__msg__Mymsg__Sequence * input,
  my_msg__msg__Mymsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_msg__msg__Mymsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_msg__msg__Mymsg * data =
      (my_msg__msg__Mymsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_msg__msg__Mymsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_msg__msg__Mymsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_msg__msg__Mymsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
