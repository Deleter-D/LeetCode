/*
    Topic link: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));

    dp[0][0] = -prices[0]; // status of holding stocks
    dp[0][1] = 0;          // status of not holding stocks
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[prices.size() - 1][1];
}

int main(int argc, char *argv[]) {
    std::vector<int> prices{7, 1, 5, 3, 6, 4};

    int res = maxProfit(prices);

    std::cout << res << std::endl;
    return 0;
}
