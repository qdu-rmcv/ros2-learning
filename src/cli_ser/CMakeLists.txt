cmake_minimum_required(VERSION 3.8)
project(cli_ser)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(zidingyi_xiaoxijiekou REQUIRED)
add_executable(node_cli src/node_cli.cpp)
add_executable(node_ser src/node_ser.cpp)
ament_target_dependencies(node_cli rclcpp zidingyi_xiaoxijiekou)
ament_target_dependencies(node_ser rclcpp zidingyi_xiaoxijiekou)

install(TARGETS
  node_cli
  node_ser
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
