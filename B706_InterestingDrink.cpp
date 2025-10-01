/*
    Problem Name: Interesting Drink
    Difficulty  : 1100
*/
#include <iostream>
#include <vector>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

// Bubble sort - Pass by reference to avoid copying the vector
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

int main() {
    // Inputs
    int numberOfShops = 1, daysForDrinks = 1;
    std::vector<int> pricesPerBottle, coinsPerDay;

    std::cin >> numberOfShops;
    pricesPerBottle.resize(numberOfShops);

    for(int i = 0; i < pricesPerBottle.size(); i++) {
        std::cin >> pricesPerBottle[i];
    }

    std::cin >> daysForDrinks;
    coinsPerDay.resize(daysForDrinks);

    for(int i = 0; i < coinsPerDay.size(); i++) {
        std::cin >> coinsPerDay[i];
    }

    // Logic
    // Insert Code here - without return statement

    // Sort price per Bottle so that one can go through the list until a bottle is more expensive than the
    // amount of coins one have for that day
    int n = pricesPerBottle.size();
    mergeSort(pricesPerBottle, 0, n - 1);
    //printVector(pricesPerBottle);

    //printVector(coinsPerDay);

    for(unsigned int i = 0; i < coinsPerDay.size(); i++) {
        // Speed check if you can buy any bottle at all
        if(coinsPerDay[i] < pricesPerBottle[0]) {
            std::cout << 0 << std::endl;
            continue;
        }
            
        // Speed check if you can buy every possible bottle
        if(coinsPerDay[i] >= pricesPerBottle.back()) {
            std::cout << pricesPerBottle.size() << std::endl;
            continue;
        }

        // Binary search
        unsigned int low = 0, high = pricesPerBottle.size()-1, mid = 0;
        while(high != low+1) {
            //std::cout << i << ": low=" << low << " old mid=" << mid << " new mid=" << low + (high - low) / 2 << "  high=" << high << std::endl;
            mid = low + (high - low) / 2;
            if(pricesPerBottle[mid] > coinsPerDay[i]) {
                high = mid;
            } else {
                low = mid;
            }
        }
        //std::cout << "Final values: low=" << low << "  mid=" << mid << "  high=" << high << std::endl;
        std::cout << high << std::endl;
    }

    // Outputs - Here inserted into the logic
}