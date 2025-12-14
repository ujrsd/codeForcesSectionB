/*
    Problem Name: A and B and Compilation Errors
    Difficulty  : 1100
    Link        : https://codeforces.com/problemset/problem/519/B
*/
#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    // Inputs
    size_t amountCompilationErrors = 3;
    std::cin >> amountCompilationErrors;

    std::vector<size_t> errorsFirstCompilation(amountCompilationErrors);
    for(int i = 0; i < amountCompilationErrors; i++) std::cin >> errorsFirstCompilation[i];

    std::vector<size_t> errorsSecondCompilation(amountCompilationErrors-1);
    for(int i = 0; i < amountCompilationErrors-1; i++) std::cin >> errorsSecondCompilation[i];

    std::vector<size_t> errorsThirdCompilation(amountCompilationErrors-2);
    for(int i = 0; i < amountCompilationErrors-2; i++) std::cin >> errorsThirdCompilation[i];

    // Logic
    // Insert Code here - without return statement
    std::sort(errorsFirstCompilation.begin(), errorsFirstCompilation.end());
    std::sort(errorsSecondCompilation.begin(), errorsSecondCompilation.end());
    std::sort(errorsThirdCompilation.begin(), errorsThirdCompilation.end());

    /*
    std::cout << "errorsFirstCompilation: ";
    for(size_t val : errorsFirstCompilation) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "errorsSecondCompilation: ";
    for(size_t val : errorsSecondCompilation) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "errorsThirdCompilation: ";
    for(size_t val : errorsThirdCompilation) std::cout << val << " ";
    std::cout << std::endl;
    */

    size_t diff = 0, res1 = 0, res2 = 0;
    for(int i = 0; i < errorsThirdCompilation.size(); i++) {
        if(errorsFirstCompilation[i] != errorsSecondCompilation[i] && res1 == 0)
            res1 = errorsFirstCompilation[i];

        if(errorsSecondCompilation[i] != errorsThirdCompilation[i] && res2 == 0)
            res2 = errorsSecondCompilation[i];

        if(res1 != 0 && res2 != 0) {
            break;
        }
    }

    if(res2 == 0) {
        res2 = errorsSecondCompilation[errorsSecondCompilation.size()-1];
    }

    if(res1 == 0) {
        if(errorsSecondCompilation[errorsSecondCompilation.size()-1] == errorsFirstCompilation[errorsFirstCompilation.size()-2]) {
            res1 = errorsFirstCompilation[errorsFirstCompilation.size()-1];
        } else {
            res1 = errorsFirstCompilation[errorsFirstCompilation.size()-2];
        }
    }

    // Outputs
    std::cout << res1 << std::endl << res2 << std::endl;
}