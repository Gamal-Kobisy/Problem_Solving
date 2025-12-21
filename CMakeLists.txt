cmake_minimum_required(VERSION 3.30)
project(Problem_Solving)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Problem_Solving
        "Minimize The Integer.cpp"
        "Shortest_Routes_I.cpp"
        #        Queries.cpp
        #        "Polynomial Queries.cpp"
        #        "Copy String.cpp"
        #        "Query on a tree II.cpp"
        #        "Minimal Grid Path.cpp"
        #        "Breach of Faith.cpp"
                 Pearls.cpp
        "The Three Olive Trees.cpp"
        "MTI or MIT.cpp"
        maxA.cpp
        "String Ordering.cpp"
        "Olive Harvest.cpp"
        "Ayman and Elnaggar in the Escape Room.cpp"
        "Mundo Game.cpp"
        gcdq.cpp
        #         Cubes.cpp
)
