# AP1 - Ex1
## First assignment in Advanced Programming 1
![uml](https://user-images.githubusercontent.com/76645845/128697955-63860283-4e9f-4852-80e8-767b47bcf9de.png)

## What is KNN Clasifier
In statistics, the k-nearest neighbors algorithm (k-NN) is a non-parametric classification method first developed by Evelyn Fix and Joseph Hodges in 1951, and later expanded by Thomas Cover. It is used for classification and regression. In both cases, the input consists of the k closest training examples in data set. The output depends on whether k-NN is used for classification or regression:

In k-NN classification, the output is a class membership. An object is classified by a plurality vote of its neighbors, with the object being assigned to the class most common among its k nearest neighbors (k is a positive integer, typically small). If k = 1, then the object is simply assigned to the class of that single nearest neighbor.

## How To Run The Classifier
In Order to run our classifier, you will need to have two csv files, containing the data.
They will need to be stored in the `./data` folder.

 - **classified.csv** - data set which contains 3 kinds of irises (versicolor, virginica, setosa), for every iris you will need to assign four properties (width, sepal length, sepal width, petal length). this dataset is being use to classify other irises, therefore this dataset will contain all irises with their known type.

Example:
```
5.4,3.9,1.7,0.4,Iris-setosa
5.0,2.0,3.5,1.0,Iris-versicolor
6.3,2.7,4.9,1.8,Iris-virginica
```

 - **unclassified.csv** - a dataset which contains the unclassified irises 4 values.

Example:
```
4.6,3.1,1.5,0.2
6.9,3.1,4.9,1.5
6.3,3.3,6,2.5
```

Clone the git using
```
git clone https://github.com/idanturkenits/AP1-ex1
```
Now you can cd to the file and run it (if you run it using Cmake it will work fine, otherwise you will need to create a new folder, cd to it, and run the program from there)

Have Fun Classifying!

## Special improvements
- We have used `std::multimap` in order to sort the Objects by distance. doing so in `n*log(n)`.
- We have a Pure Abstract Class named `Classifier`, which KNN inherits from.
- We have a Abstract Class named `Classified`, which is an Object to be Classified by some `Classifier`. It has an abstract virtual method `getDistance()`, which returns the distance from the current Classified Object to another. It is abstract because Distances can be measured differently.
