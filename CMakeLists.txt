cmake_minimum_required(VERSION 3.27)
project(Problem_Solving)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2 -mbmi -mbmi2 -mlzcnt -mpopcnt")
set(CMAKE_CXX_STANDARD 14)

add_executable(Problem_Solving
        "Math Division.cpp"
        #        "Price Tags.cpp"
        #        "DZY Loves Fibonacci Numbers.cpp"
        #        Meteors.cpp

)
