/*
    Topic link:
   https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
*/
#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5, 0));

    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    dp[0][3] = -prices[0];
    dp[0][4] = 0;

    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }

    return dp[prices.size() - 1][4];
}

int main(int argc, char *argv[]) {
    std::vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};

    int res = maxProfit(prices);

    std::cout << res << std::endl;
    return 0;
}
