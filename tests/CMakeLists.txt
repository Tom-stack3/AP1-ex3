cmake_minimum_required(VERSION 3.0.0)

add_executable(
  Tests
  test.cpp

  # Utils
  ../utils/InputValidator.cpp
  ../utils/StringFunctions.cpp
  ../utils/Reader.cpp

  # Server
  ../server/DataManager.cpp

  # Commands
  ../server/commands/Command.cpp
  ../server/commands/UploadCommand.cpp
  ../server/commands/ClassifyCommand.cpp
  ../server/commands/SettingsCommand.cpp
  ../server/commands/DisplayCommand.cpp

  # Classifier
  ../classifier/Classifier.cpp
  ../classifier/Classified.cpp
  ../classifier/KNNClassifier.cpp
  ../classifier/Algorithm.cpp

  # Distance metrics
  ../classifier/distance/EucDistance.cpp
  ../classifier/distance/ManDistance.cpp
  ../classifier/distance/CheDistance.cpp)
