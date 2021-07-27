#include "Flower.h"
#include "vector"
class KNNClassifier
{
private:
    std::vector<Flower> data;
    std::vector<Flower> findKNN(const int k, const Flower &f);

public:
    // Overiding the interface function.
    KNNClassifier(std::vector<Flower> data);
    std::string predict(const Flower &f);
};