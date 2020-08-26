PROJECT(Pillpopper)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

cmake_minimum_required(VERSION 2.8.0)

find_package(SFML REQUIRED audio graphics window system)
include_directories(${SFML_INCLUDE_DIR})


set(CMAKE_CXX_FLAGS "-s -Wall -O2")

# determine source and header files
file(GLOB PILLPOPPER_SOURCES *.cpp)
file(GLOB PILLPOPPER_HEADERS *.hpp)

add_executable(
  pillpopper
  main.cpp
  ${PILLPOPPER_SOURCES}
  ${PILLPOPPER_HEADERS}
)

# link SFML and other libraries
target_link_libraries(
  pillpopper
  ${SFML_LIBRARIES}
  #${OPENGL_LIBRARIES}
  ${XRANDR_LIBRARY}
)

install(TARGETS pillpopper DESTINATION ${PROJECT_SOURCE_DIR})
