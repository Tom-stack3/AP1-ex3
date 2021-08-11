cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ex2 main.cpp Socket.cpp Tcp.cpp Udp.cpp Flower.cpp Writer.cpp Reader.cpp KNNClassifier.cpp Algorithm.cpp Classified.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
