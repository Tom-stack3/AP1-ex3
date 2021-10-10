cmake_minimum_required(VERSION 3.0.0)
project(serverAndClient)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(server)
add_subdirectory(client)

# Tests:
#add_subdirectory(tests)