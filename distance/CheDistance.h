#ifndef CHE_DISTANCE_H
#define CHE_DISTANCE_H
#include "../Classified.h"
#include <math.h>

class Classified; // forward declaration 

class CheDistance
{
public:
    /**
     * Get chebyshev distance between two classified objects.
     */
    static double getDist(const Classified &cls1, const Classified &cls2);
};

#endif