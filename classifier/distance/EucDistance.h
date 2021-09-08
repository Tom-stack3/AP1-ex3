#ifndef EUC_DISTANCE_H
#define EUC_DISTANCE_H
#include "../Classified.h"
#include <math.h>

class Classified; // forward declaration

class EucDistance
{
public:
    /**
     * Get euclidean distance between two classified objects.
     */
    static double getDist(const Classified &cls1, const Classified &cls2);
};

#endif