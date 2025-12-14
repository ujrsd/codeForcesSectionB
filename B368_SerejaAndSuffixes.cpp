/*
    Problem Name: Sereja and Suffixes
    Difficulty  : 1100
    Link        : https://codeforces.com/problemset/problem/368/B
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>

int main() {
    // Inputs
    unsigned int arrayLengthA = 1, arrayLengthL = 1;
    std::cin >> arrayLengthA >> arrayLengthL;
    
    std::vector<unsigned int> a(arrayLengthA), l(arrayLengthL);

    for(int i = 0; i < arrayLengthA; i++) std::cin >> a[i];
    for(int i = 0; i < arrayLengthL; i++) std::cin >> l[i];

    // Logic
    // Insert Code here - without return statement
    std::vector<int> amountDistinctNumberPerIndex(arrayLengthA);
    std::unordered_set<int> seen;

    for (int i = arrayLengthA - 1; i >= 0; i--) {
        seen.insert(a[i]);
        amountDistinctNumberPerIndex[i] = seen.size();
    }

    // Outputs
    for(int i = 0; i < l.size(); i++) std::cout << amountDistinctNumberPerIndex[l[i]-1] << std::endl;
}