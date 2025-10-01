/*
    Problem Name: Taxi
    Difficulty  : 1100
*/
#include <iostream>
#include <vector>

int main() {
    // Inputs
    unsigned int numberOfGroups = 1; // 1 <= n <= 10^5
    std::vector<unsigned int> groupSizes;

    std::cin >> numberOfGroups;
    groupSizes.resize(numberOfGroups);

    unsigned int amountOf4Groups = 0, amountOf3Groups = 0, amountOf2Groups = 0, amountOf1Groups = 0, taxisNeeded = 0, currentValue;
    for(int i = 0; i < groupSizes.size(); i++) {
        std::cin >> currentValue;
        groupSizes[i] = currentValue;

        switch (currentValue) {
        case 1:
            amountOf1Groups++;
            break;
        case 2:
            amountOf2Groups++;
            break;
        case 3:
            amountOf3Groups++;
            break;
        case 4:
            amountOf4Groups++;
            break;
        default:
            break;
        }
    }

    // Logic
    // Add amount of taxis needed for 4-groups
    taxisNeeded += amountOf4Groups;
    amountOf4Groups = 0;

    // Add amount of taxis needed for 3-groups
    taxisNeeded += amountOf3Groups;
    if(amountOf1Groups <= amountOf3Groups) {
        amountOf3Groups -= amountOf1Groups;
        amountOf1Groups = 0;
    } else {
        amountOf1Groups -= amountOf3Groups;
        amountOf3Groups = 0;
    }

    // Add amount of taxis needed for 2-groups
    taxisNeeded += amountOf2Groups/2;
    if(amountOf2Groups%2 != 0) {
        if(amountOf1Groups > 1)
            amountOf1Groups -= 2;
        else {
            if(amountOf1Groups == 1)
                amountOf1Groups--;
        }
        taxisNeeded++;
    }
    amountOf2Groups = 0;

    // Add amount of taxis needed for 1-groups
    taxisNeeded += amountOf1Groups/4;
    if(amountOf1Groups%4 != 0) {
        taxisNeeded++;
    }
    amountOf1Groups = 0;

    // Outputs
    std::cout << taxisNeeded << std::endl;
}