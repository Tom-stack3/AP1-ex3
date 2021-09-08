#ifndef MAN_DISTANCE_H
#define MAN_DISTANCE_H
#include "../Classified.h"
#include <math.h>

class Classified; // forward declaration

class ManDistance
{
public:
    /**
     * Get manhattan distance between two classified objects.
     */
    static double getDist(const Classified &cls1, const Classified &cls2);
};

#endif