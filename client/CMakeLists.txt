cmake_minimum_required(VERSION 3.0.0)

add_executable(
Client
Client.cpp

# Utils
../utils/InputValidator.cpp
../utils/StringFunctions.cpp
../utils/Reader.cpp
../utils/Writer.cpp

# Classifier
../classifier/Classified.cpp

# Communication Protocols
../protocol/Socket.cpp
../protocol/Tcp.cpp)

# For threads
find_package (Threads)
target_link_libraries (Client ${CMAKE_THREAD_LIBS_INIT})