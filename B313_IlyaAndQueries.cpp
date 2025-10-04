/*
    Problem Name: Ilya and Queries
    Difficulty  : 1100
    Link        : https://codeforces.com/problemset/problem/313/B
*/
#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    // Inputs
    std::string text = "";
    unsigned int amountOfQuerries = 1;

    std::cin >> text; // Contains only '.' and '#'
    std::cin >> amountOfQuerries;

    std::vector<std::pair<unsigned int, unsigned int>> querries(amountOfQuerries);

    for(int i = 0; i < amountOfQuerries; i++) {
        std::cin >> querries[i].first >> querries[i].second;
    }

    // Logic
    // Insert Code here - without return statement
    std::vector<unsigned int> result(amountOfQuerries, 0);
    std::vector<unsigned int> counterValues(text.size());
    unsigned int counter = 0;

    for(int i = 0; i < counterValues.size()-1; i++) {
        char left = text[i], right = text[i+1];
        counterValues[i] = counter;

        if(left == right) counter++;
    }
    counterValues[counterValues.size()-1] = counter;
    
    //std::cout << "Counter Values: ";
    //for(unsigned int val : counterValues) std::cout << val << " ";
    //std::cout << std::endl;

    for(int i = 0; i < amountOfQuerries; i++) {
        result[i] = counterValues[querries[i].second-1] - counterValues[querries[i].first-1];
    }
    
    // Outputs
    for(unsigned int val : result) std::cout << val << std::endl;
}