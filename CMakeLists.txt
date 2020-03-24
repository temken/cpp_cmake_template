cmake_minimum_required(VERSION 3.2)

project(cpp_project)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
# Require (at least) it
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Don't use e.g. GNU extension (like -std=gnu++11) for portability
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -O3")

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Code Coverage Configuration
add_library(coverage_config INTERFACE)

option(CODE_COVERAGE "Enable coverage reporting" OFF)

# if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
if(CODE_COVERAGE)
  # Add required flags (GCC & LLVM/Clang)
  target_compile_options(coverage_config INTERFACE
    -O0        # no optimization
    -g         # generate debug info
    --coverage # sets all required flags
  )
  if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
    target_link_options(coverage_config INTERFACE --coverage)
  else()
    target_link_libraries(coverage_config INTERFACE --coverage)
  endif()
endif(CODE_COVERAGE)
# endif(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

include_directories( ${INCLUDE_DIR} )

add_subdirectory(${SRC_DIR})