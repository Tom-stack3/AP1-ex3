cmake_minimum_required(VERSION 3.0.0)

add_executable(Client Client.cpp ../protocol/Udp.cpp ../protocol/Tcp.cpp ../protocol/Socket.cpp ../Classified.cpp ../utils/Reader.cpp ../utils/Writer.cpp ../distance/EucDistance.cpp)