#! /bin/bash

BUILD_PATH=""
TARGET="../bin/"
TEST_FILTER=""

for i in "$@"
do
case $i in
  -e=*|--test)
  BUILD_PATH="../src/test"
  ;;
  
  -e=*|--runtest=*)
  TARGET="$TARGET${i#*=}"
  ;;
  -e=*|--gtest_filter=*)
  TEST_FILTER="${i#*=}"
  ;;  
esac
done

# Generate makefile for test project
cmake $BUILD_PATH

# build the project in current folder
make

if [ -n $TARGET ] && [ -n $TEST_FILTER ]; then
  echo "Running test: ${TARGET} with filter="$TEST_FILTER
  $TARGET --gtest_filter="*"$TEST_FILTER"*"
elif [ -n $TARGET ] && [ -z $TEST_FILTER ]; then
  echo "Running test: ${TARGET}"
  $TARGET
fi