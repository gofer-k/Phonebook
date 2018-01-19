#! /bin/sh

# Generate makefile for test project
cmake ..

# build the project in current folder
make

PARAMCOUNT=$#

if [ $PARAMCOUNT -lt 2 ]; then
  # run all test bult above
  ./$1
elif [[ $2 == *"--gtest_filter="* ]]; then
  # run specified subset of tests
  ./$1 $2
fi