cmake_minimum_required(VERSION 3.0.0)

add_executable(Client Client.cpp ../protocol/Udp.cpp ../protocol/Tcp.cpp ../protocol/Socket.cpp ../classifier/Classified.cpp ../utils/Reader.cpp ../utils/Writer.cpp ../classifier/distance/EucDistance.cpp ../classifier/distance/ManDistance.cpp ../classifier/distance/CheDistance.cpp)