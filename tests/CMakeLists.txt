cmake_minimum_required(VERSION 3.0.0)

add_executable(Tests test.cpp ../utils/InputValidator.cpp ../utils/StringFunctions.cpp ../utils/Reader.cpp ../classifier/Classified.cpp ../classifier/distance/EucDistance.cpp ../classifier/distance/ManDistance.cpp ../classifier/distance/CheDistance.cpp)