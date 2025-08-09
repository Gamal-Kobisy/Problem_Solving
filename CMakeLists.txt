# CMakeList.txt : CMake project for Problem Solving, include source and define
# project specific logic here.
#

# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(ProblemSolving)

# Add source files to this project's executable
add_executable(CMakeTarget
#        test.cpp
#        "Trading Routes.cpp"
#        "Oops!. . . They Did It Again.cpp"
#        "Designing the Wall.cpp"
#        "Lost Library of C´ordoba.cpp"
#        "Segment Tree for the Sum.cpp"
#        "Segment Tree for the Minimum.cpp"
#        "Number of Minimums on a Segment.cpp"
        "Segment with the Maximum Sum.cpp"
#        "K-th one.cpp"
#        "First element at least X - 2.cpp"
#        "First element at least X.cpp"
#        "Addition to Segment.cpp"
#        "Applying MAX to Segment.cpp"
#        "Assignment to Segment.cpp"
#        "Addition and Minimum.cpp"
#        "Multiplication and Sum.cpp"
#        "Bitwise OR and AND.cpp"
#        "Addition and Sum.cpp"
#        "Assignment and Minimum.cpp"
        "Assignment and Sum.cpp"
                "Static Range Minimum Queries.cpp"
        #        test.cpp
#        "Bracket Sequences II.cpp"
        #        Woodcutters_Dp.cpp
        #        "Two Sets II.cpp"
        #        "Sports Betting.cpp"
        #        Goblin.cpp

)

# Set the C++ standard if CMake version is greater than 3.12
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.