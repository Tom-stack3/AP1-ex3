cmake_minimum_required(VERSION 3.0.0)

add_executable(Server Server.cpp ../protocol/Udp.cpp ../protocol/Tcp.cpp ../protocol/Socket.cpp ../utils/Reader.cpp ../utils/Writer.cpp ../Classified.cpp ../Flower.cpp ../KNNClassifier.cpp ../Algorithm.cpp)