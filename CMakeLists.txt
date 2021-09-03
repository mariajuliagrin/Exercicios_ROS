cmake_minimum_required(VERSION 3.0.2)
project(Exercicios_ROS)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)



## Generate services in the 'srv' folder
add_service_files(FILES AddTwoInts1.srv)



## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
 )



catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES Exercicios_ROS
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/Exercicios_ROS.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(talker1 src/talker1.cpp)
add_executable(listener1 src/listener1.cpp)
add_dependencies(talker1 Exercicios_ROS_generate_messages_cpp)
add_dependencies(listener1 Exercicios_ROS_generate_messages_cpp)
target_link_libraries(talker1 ${catkin_LIBRARIES})
target_link_libraries(listener1 ${catkin_LIBRARIES})
add_executable(add_two_ints_server1 src/add_two_ints_server1.cpp)
target_link_libraries(add_two_ints_server1 ${catkin_LIBRARIES})
add_dependencies(add_two_ints_server1 Exercicios_ROS_gencpp)

add_executable(add_two_ints_client1 src/add_two_ints_client1.cpp)
target_link_libraries(add_two_ints_client1 ${catkin_LIBRARIES})
add_dependencies(add_two_ints_client1 Exercicios_ROS_gencpp)



catkin_install_python(PROGRAMS scripts/talker1.py scripts/listener1.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
catkin_install_python(PROGRAMS scripts/talker1.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)



