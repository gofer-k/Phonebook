import argparse
from subprocess import check_output
from subprocess import CalledProcessError

import os

#---------- Commanf line arguments definition ------------
parser=argparse.ArgumentParser()
parser.add_argument("build", help="target_binary name to build. Can be either an application, library or test")
parser.add_argument("-t", "--runtest", help="Execute test", action="store_true")
parser.add_argument("-f", "--filter", help="Run only tests matching filter")

args = parser.parse_args()
#---------------------

#---------- Setup ------------
current_folder = os.getcwd()

cmake_folder = current_folder + "/CMakeOutput"
os.makedirs(cmake_folder, 0773)
os.chdir(cmake_folder)
#---------- ------------

target_binary = current_folder + "/../bin/" + args.build
target_cmake = current_folder + "/../src"
test_filter = ""

if args.runtest:
  target_cmake = current_folder + "/../src/test"
  print "Running test: {}".format(args.build)

if args.filter:
  print "with filter: {}".format(args.filter)
  test_filter = "--gtest_filter=*{}*".format(args.filter)

print "Command to execute: {} {}".format(target_binary, test_filter)

error_message = ""

try:
  # Generate makefile for given project
  error_message = check_output(["cmake", target_cmake])

  # Build project in current folder
  error_message = check_output("make")

  # Install project in folder configured in CMakeLists.txt file
  error_message = check_output(["make", "install"])

  # Remove project binary from current folder after successfull installation
  error_message = check_output(["make", "clean"])

  # Execute target_binary with optional arguments
  if args.runtest:
    error_message = check_output([target_binary, str(args.runtest), str(test_filter)])

except CalledProcessError:
  print "Build failed. Reason:"
  print error_message


