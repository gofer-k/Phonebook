#! /bin/sh

# Generate makefile for test project
cmake ..

# build the project in current folder
make

PARAMCOUNT=$#

if [ $PARAMCOUNT -eq 1 ]; then
  # run all test bult above
  $1
elif [[ $PARAMCOUNT -eq 2 && $2 == *"--gtest_filter="* ]]; then
  # run specified subset of tests
  $1 $2
fi