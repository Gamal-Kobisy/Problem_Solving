# CMakeList.txt : CMake project for Problem Solving, include source and define
# project specific logic here.
#

# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(ProblemSolving)

# Add source files to this project's executable
add_executable(CMakeTarget
        "Flower Boy.cpp"
)

# Set the C++ standard if CMake version is greater than 3.12
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.