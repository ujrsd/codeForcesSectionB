/*
    Problem Name: Fence
    Difficulty  : 1100
    Link        : https://codeforces.com/problemset/problem/363/B
*/
#include <iostream>
#include <vector>

int main() {
    // Inputs
    unsigned int planks = 1, widthPiano = 1;

    std::cin >> planks >> widthPiano;

    std::vector<unsigned int> plankHeights(planks);
    for(int i = 0; i < plankHeights.size(); i++) std::cin >> plankHeights[i];

    // Logic
    unsigned int smallestSum = 0, sum = 0, bestPosition = 1;

    for(int i = 0; i < widthPiano; i++) smallestSum += plankHeights[i];
    //std::cout << "Start smallestSum = " << smallestSum << std::endl;
    sum = smallestSum;

    for(int i = widthPiano; i < plankHeights.size(); i++) {
        sum = sum - plankHeights[i-widthPiano] + plankHeights[i];
        
        if(sum < smallestSum) {
            bestPosition = i-widthPiano+2;
            smallestSum = sum;
        }
        //std::cout <<  "new Sum = " << sum << " i = " << i << " smallestSum = " << smallestSum << std::endl;
    }

    // Output
    std::cout << bestPosition << std::endl;
}