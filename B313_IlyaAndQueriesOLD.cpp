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
    std::vector<std::pair<std::size_t, std::size_t>> chainSegments;
    char symbol = text[0] == '.' ? '#' : '.';
    std::size_t position = text.find(symbol, 0), lastPosition = 0;

    do {
        if(position - lastPosition > 1) {
            chainSegments.push_back({lastPosition, position-1});
        }
        
        lastPosition = position;
        symbol = text[position] == '.' ? '#' : '.';
        position = text.find(symbol, position);
    } while(position != std::string::npos);

    //std::cout << "text.size()-1=" << text.size()-1 << " lastPosition=" << lastPosition << std::endl;
    if(text.size()-1 - lastPosition > 0) {
        chainSegments.push_back({lastPosition, text.size()-1});
    }

    
    //std::cout << "Chain Lengths: ";
    //for(int i = 0; i < chainSegments.size(); i++) std::cout << "{" << chainSegments[i].first << "," << chainSegments[i].second << "} ";
    //std::cout << std::endl;
    

    if(!chainSegments.empty()) {
        for(int i = 0; i < amountOfQuerries; i++) {
            unsigned int firstPosition = querries[i].first-1;
            unsigned int secondPosition = querries[i].second-1;
            unsigned int sum = 0;

            for(int j = 0; j < chainSegments.size(); j++) {
                if(firstPosition > chainSegments[j].second || secondPosition < chainSegments[j].first) continue;

                if(firstPosition < chainSegments[j].first && secondPosition > chainSegments[j].second){
                    sum += (chainSegments[j].second - chainSegments[j].first);
                } else if(firstPosition >= chainSegments[j].first && secondPosition > chainSegments[j].second) {
                    sum += (chainSegments[j].second - firstPosition);
                } else if(firstPosition < chainSegments[j].first && secondPosition <= chainSegments[j].second) {
                    sum += (secondPosition - chainSegments[j].first);
                } else if(firstPosition >= chainSegments[j].first && secondPosition <= chainSegments[j].second) {
                    sum += (secondPosition - firstPosition);
                }
            }
            result[i] = sum;
        }
    }

    // Outputs
    for(unsigned int val : result) std::cout << val << std::endl;
}