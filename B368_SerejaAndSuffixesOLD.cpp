/*
    Problem Name: Sereja and Suffixes
    Difficulty  : 1100
    Link        : https://codeforces.com/problemset/problem/368/B
*/
#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    // Inputs
    unsigned int arrayLengthA = 1, arrayLengthL = 1;
    std::cin >> arrayLengthA >> arrayLengthL;
    
    std::vector<unsigned int> a(arrayLengthA), l(arrayLengthL);
    for(int i = 0; i < arrayLengthA; i++) std::cin >> a[i];
    for(int i = 0; i < arrayLengthL; i++) std::cin >> l[i];

    /*
    std::cout << "a: ";
    for(int i = 0; i < a.size(); i++) std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "l: ";
    for(int i = 0; i < l.size(); i++) std::cout << l[i] << " ";
    std::cout << std::endl;
    */

    // Logic
    // Insert Code here - without return statement
    std::vector<unsigned int> amountDistinctNumberPerIndex(arrayLengthA);
    std::vector<unsigned int> distinctNumbers;
    distinctNumbers.push_back(a[0]);
    
    for(int j = 1; j < a.size(); j++) {
        unsigned int counter = 0;
        for(int k = 0; k < distinctNumbers.size(); k++) {
            if(a[j] == distinctNumbers[k]) {
                break;
            } else {
                counter++;
            }
        }
        
        if(counter == distinctNumbers.size())
            distinctNumbers.push_back(a[j]);
    }

    /*
    std::cout << "distinctNumbers: ";
    for(int i = 0; i < distinctNumbers.size(); i++) std::cout << distinctNumbers[i] << " ";
    std::cout << std::endl;
    */

    unsigned int lastSize = distinctNumbers.size();
    amountDistinctNumberPerIndex[0] = distinctNumbers.size();
    for(int i = 0; i < a.size()-1; i++) {
        bool foundAnother = false;
        for(int j = i+1; j < a.size(); j++) {
            if(a[i] == a[j]) {
                foundAnother = true;
                break;
            }
        }

        if(!foundAnother)
            lastSize--;
        
        amountDistinctNumberPerIndex[i+1] = lastSize;
    }

    /*
    std::cout << "amountDistinctNumberPerIndex: ";
    for(int k = 0; k < amountDistinctNumberPerIndex.size(); k++) std::cout << amountDistinctNumberPerIndex[k] << " ";
    std::cout << std::endl;
    */

    // Outputs
    for(int i = 0; i < l.size(); i++) std::cout << amountDistinctNumberPerIndex[l[i]-1] << std::endl;
}