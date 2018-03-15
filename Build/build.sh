#! /bin/bash

# pass command line arugments to python script for further processing
python ./build.py "$@"

# Generate makefile for test project
# cmake $BUILD_PATH

# # build the project in current folder
# make

# if [ -n $RUNTEST ] && [ -n $TEST_FILTER ]; then
#   echo "Running test: ${TARGET} with filter="$TEST_FILTER
#   $TARGET --gtest_filter="*"$TEST_FILTER"*"
# elif [ -n $RUNTEST ] && [ -z $TEST_FILTER ]; then
#   echo "Running test: ${TARGET}"
#   $TARGET
# fi