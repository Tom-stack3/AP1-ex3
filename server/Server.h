#ifndef SERVER_H
#define SERVER_H
#include "../Flower.h"
#include "../Classifier.h"
#include "../KNNClassifier.h"

#include "../utils/Writer.h"
#include "../utils/Reader.h"

#include "../protocol/Socket.h"
#include "../protocol/Tcp.h"
#include "../protocol/Udp.h"

#include <iostream>
#include <algorithm>

int main(int argc, char **argv);

#endif