# AP1 - Ex1
## First assignment in Advanced Programming 1

## What is KNN Clasifier
In statistics, the k-nearest neighbors algorithm (k-NN) is a non-parametric classification method first developed by Evelyn Fix and Joseph Hodges in 1951, and later expanded by Thomas Cover. It is used for classification and regression. In both cases, the input consists of the k closest training examples in data set. The output depends on whether k-NN is used for classification or regression:

In k-NN classification, the output is a class membership. An object is classified by a plurality vote of its neighbors, with the object being assigned to the class most common among its k nearest neighbors (k is a positive integer, typically small). If k = 1, then the object is simply assigned to the class of that single nearest neighbor.


## How To Run The Classifier
In Order to run our classifier, you will need to have two csv files

 - **classified.csv** - data set which contains 3 kinds of irises (versicolor, virginica, setosa), for every iris you will need to assign four properties (width, sepal length, sepal width, petal length). this dataset is being use to classify other irises, therefore this dataset will contain all irises with their known type.

Example: (Tommi add pic because csv files on mac look like shit)

 - **unclassified.csv** - a dataset which contains the unclassified irises 4 values.

Example: (Tommi add pic because csv files on mac look like shit)

Clone the git using
```
git clone https://github.com/idanturkenits/AP1-ex1
```
now you can cd to the file and run it (if you run it using Cmake it will work fine, otherwise you will need to create a new folder, cd to it, and run the program from there)

Have Fun Classifying!


