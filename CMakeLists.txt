cmake_minimum_required(VERSION 3.18)

project(FLUID_DEV)

### C++
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard required for build")
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "is C++ stndard a requirement")
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "enable/disable compiler specific extensions")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Werror -std=c++11")

set(SRC_DIR src)

include_directories(
  ${CMAKE_SOURCE_DIR}/${SRC_DIR}/ringbuffer
  ${CMAKE_SOURCE_DIR}/${SRC_DIR}/fdm
  ${CMAKE_SOURCE_DIR}/${SRC_DIR}/common
  ${CMAKE_SOURCE_DIR}/${SRC_DIR}/encoder
)


add_subdirectory(src)
add_subdirectory(test)
