/*
    Topic link: https://leetcode.cn/problems/last-stone-weight-ii/
*/
#include "utils/DPUtils.h"
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int lastStoneWeightII(std::vector<int> &stones) {
    std::vector<int> dp(1501, 0);

    int sum =
        std::accumulate(stones.begin(), stones.end(), 0, std::plus<int>());

    int target = sum / 2;

    for (int i = 0; i < stones.size(); i++) {
        for (int j = target; j >= stones[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            printDP(dp);
        }
    }

    return sum - dp[target] - dp[target];
}

int main(int argc, char *argv[]) {
    std::vector<int> stones{1, 2};

    int res = lastStoneWeightII(stones);

    std::cout << res << std::endl;
    return 0;
}
