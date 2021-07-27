#include "Flower.h"
using namespace std;
class KNNClassifier{
    private:
    Flower data [];
    int dataSize;
    Flower (Flower [] data, int dataSize);
    Flower& findKNN(const int k,const Flower & f);

    public:
    // Overiding the interface function.
    string predict(const Flower & f);
};