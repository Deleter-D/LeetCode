/*
    Topic link: https://leetcode.cn/problems/min-cost-climbing-stairs/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int> &cost) {
    if (cost.size() == 2)
        return std::min(cost[0], cost[1]);

    std::vector<int> dp(cost.size() + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= cost.size(); i++) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[cost.size()];
}

int main(int argc, char *argv[]) {
    std::vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    int res = minCostClimbingStairs(cost);

    std::cout << res << std::endl;
    return 0;
}
