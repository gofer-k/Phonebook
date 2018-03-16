import argparse
from subprocess import check_output
from subprocess import CalledProcessError
from subprocess import STDOUT
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

if not os.path.exists(cmake_folder):
  os.makedirs(cmake_folder, 0773)

os.chdir(cmake_folder)
#---------- ------------

target_binary = current_folder + "/../bin/" + args.build
target_cmake = "../.."
test_filter = ""

if args.runtest:
  print "Running test: {}".format(args.build)

if args.filter:
  print "with filter: {}".format(args.filter)
  test_filter = "--gtest_filter=*{}*".format(args.filter)

print "Command to execute: {} {}".format(target_binary, test_filter)

try:
  # Generate makefile for given project
  check_output(["cmake", target_cmake])

  # Build project in current folder
  check_output(["cmake", "--build", ".", "--target", args.build])

  # Install project in folder configured in CMakeLists.txt file
  check_output(["make", "install"])

  # Remove project binary from current folder after successfull installation
  check_output(["make", "clean"])

  # Execute target_binary with optional arguments
  if args.runtest:
    check_output([target_binary, str(test_filter)])
    print "All tests passed"
  
except CalledProcessError, exp:
  print exp.message
  print exp.returncode
  print exp.output

