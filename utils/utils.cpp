#include "utils.h"

// Bubble sort
template <typename T>
void sortVector(std::vector<T>& values) {
    unsigned int bestPosition = 0, bestValue = 0, oldValue = 0;
    for(int i = 0; i < values.size(); i++) {
        for(int j = 0; j < values.size()-i; j++) {
            if(bestValue < values[j]) {
                bestPosition = j;
                bestValue = values[j];
            }
        }
        values[bestPosition] = values[values.size()-1-i];
        values[values.size()-1-i] = bestValue;
        bestValue = 0;
    }
}

// Merge Sort
void merge(std::vector<int>& leftVector, std::vector<int>& rightVector, std::vector<int>& mainVector) {
    int leftSize = mainVector.size()/2;
    int rightSize = mainVector.size() - leftSize;
    int l = 0, i = 0, r = 0;

    while(l < leftSize && r < rightSize) {
        if(leftVector[l] < rightVector[r]) {
            mainVector[i] = leftVector[l];
            l++;
        } else {
            mainVector[i] = rightVector[r];
            r++;
        }
        i++;
    }

    while(l < leftSize) {
        mainVector[i] = leftVector[l];
        l++;
        i++;
    }

    while(r < rightSize) {
        mainVector[i] = rightVector[r];
        r++;
        i++;
    }
}

void mergeSort(std::vector<int>& mainVector) {
    if(mainVector.size() > 1) {
        int middle = mainVector.size()/2;
        std::vector<int> leftVector(mainVector.begin(), mainVector.begin()+middle);
        std::vector<int> rightVector(mainVector.begin()+middle, mainVector.end());

        mergeSort(leftVector);
        mergeSort(rightVector);
        merge(leftVector, rightVector, mainVector);
    }
}

// Print all values of a vector
template <typename T>
void printVector(const std::vector<T>& values) {
    std::cout << "Values of vector: ";
    for(const T& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// Print all values of a matrix
template <typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix) {
    std::cout << "Matrix = " << std::endl;
    for(const std::vector<T>& row : matrix) {
        std::cout << " ";
        for(const T& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

// Add up all values of a vector
template <typename T>
T sumUpVector(const std::vector<T>& values) {
    T sum = 0;
    for(const T& value : values) {
        sum += value;
    }
    return sum;
}