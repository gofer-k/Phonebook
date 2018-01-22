project(SampleGMockTest.unittest)

# We need thread support
find_package(Threads REQUIRED)

cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set(GMOCK_DIR "$ENV{GMOCK_DIR}")
set(GTEST_DIR "$ENV{GTEST_DIR}")

MESSAGE( STATUS "Target artifacts will be installed in:         " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )
MESSAGE( STATUS "Using GTest from:         " ${GTEST_DIR} )
MESSAGE( STATUS "Using GMock from:         " ${GMOCK_DIR} )

set(IMPLEMENTATION_SOURCES
  # List all implementation files to be built in this project
  SampleGMockTest.cpp
  main.cpp)

include_directories(
  "${GMOCK_DIR}/include"
  "${GTEST_DIR}/include")

link_directories(
  "${GMOCK_DIR}/Build"
  "${GMOCK_DIR}/Build/gtest")

add_executable(${PROJECT_NAME} ${IMPLEMENTATION_SOURCES})

target_link_libraries(${PROJECT_NAME}  
  gtest
  gmock
  pthread
  # add any thrid party library which is referenced in test defined in this project
)