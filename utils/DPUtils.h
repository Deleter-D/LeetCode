#include <algorithm>
#include <iostream>
#include <vector>

inline void printDP(std::vector<int> &dp) {
    std::cout << "==========DP==========" << std::endl;
    std::for_each(dp.begin(), dp.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
    std::cout << "======================" << std::endl;
}

inline void printDP(std::vector<std::vector<int>> &dp) {
    std::cout << "==========DP==========" << std::endl;
    std::for_each(dp.begin(), dp.end(), [](std::vector<int> &vec) {
        std::for_each(vec.begin(), vec.end(),
                      [](int i) { std::cout << i << " "; });
        std::cout << std::endl;
    });
    std::cout << "======================" << std::endl;
}
