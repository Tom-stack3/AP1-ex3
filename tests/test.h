#ifndef TEST_H
#define TEST_H

// Utils
#include "../utils/InputValidator.h"
#include "../utils/StringFunctions.h"
#include "../utils/Reader.h"

// IO
#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
#include "../IO/SocketIO.h"

// Server
#include "../server/DataManager.h"

// Commands
#include "../server/commands/Command.h"
#include "../server/commands/UploadCommand.h"
#include "../server/commands/ClassifyCommand.h"
#include "../server/commands/SettingsCommand.h"
#include "../server/commands/DisplayCommand.h"
#include "../server/commands/ConfusionMatrixCommand.h"

// Classifier
#include "../classifier/Classifier.h"
#include "../classifier/Classified.h"
#include "../classifier/KNNClassifier.h"
#include "../classifier/Algorithm.h"

// Distance metrics
#include "../classifier/distance/EucDistance.h"
#include "../classifier/distance/ManDistance.h"
#include "../classifier/distance/CheDistance.h"

#include <fstream>
#include <iostream>

#endif