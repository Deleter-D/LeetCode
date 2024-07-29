/*
    Topic link: https://leetcode.cn/problems/candy/
*/
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int candy(std::vector<int> &ratings) {
    std::vector<int> candyVec(ratings.size(), 1);

    // forward
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1])
            candyVec[i] = candyVec[i - 1] + 1;
    }

    // backward
    for (int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candyVec[i] = std::max(candyVec[i], candyVec[i + 1] + 1);
        }
    }

    return std::accumulate(candyVec.begin(), candyVec.end(), 0,
                           std::plus<int>());
}

int main(int argc, char *argv[]) {
    std::vector<int> ratings{1, 0, 2};

    int res = candy(ratings);

    std::cout << res << std::endl;
    return 0;
}
