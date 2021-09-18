cmake_minimum_required(VERSION 3.0.0)

add_executable(
  Server
  Server.cpp
   # Utils
  ../utils/InputValidator.cpp
  ../utils/StringFunctions.cpp
  ../utils/Reader.cpp
  ../utils/Writer.cpp
  
  # IO
  ../IO/StandardIO.cpp
  ../IO/SocketIO.cpp

  # Server
  ../server/DataManager.cpp
  ../server/CLI.cpp

  # Commands
  ../server/commands/Command.cpp
  ../server/commands/UploadCommand.cpp
  ../server/commands/ClassifyCommand.cpp
  ../server/commands/SettingsCommand.cpp
  ../server/commands/DisplayCommand.cpp
  ../server/commands/ConfusionMatrixCommand.cpp
  ../server/commands/DownloadCommand.cpp

  # Classifier
  ../classifier/Classifier.cpp
  ../classifier/Classified.cpp
  ../classifier/KNNClassifier.cpp
  ../classifier/Algorithm.cpp

  # Distance metrics
  ../classifier/distance/EucDistance.cpp
  ../classifier/distance/ManDistance.cpp
  ../classifier/distance/CheDistance.cpp

  # Communication Protocols
  ../protocol/Socket.cpp
  ../protocol/Tcp.cpp
  ../protocol/TcpServer.cpp)

# For threads
find_package (Threads)
target_link_libraries (Server ${CMAKE_THREAD_LIBS_INIT})