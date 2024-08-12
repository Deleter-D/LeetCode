/*
    Topic link:
   https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/
#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
    int n = prices.size();
    if (n == 0)
        return 0;

    std::vector<std::vector<int>> dp(n, std::vector<int>(4, 0));

    dp[0][0] = -prices[0]; // status of holding stocks
    dp[0][1] = 0;          // status of keeping not hold stocks
    dp[0][2] = 0;          // status of selling stocks today
    dp[0][3] = 0;          // status of frozen period

    for (int i = 1; i < n; i++) {
        dp[i][0] = std::max(dp[i - 1][0], std::max(dp[i - 1][1] - prices[i],
                                                   dp[i - 1][3] - prices[i]));
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][2] = dp[i - 1][0] + prices[i];
        dp[i][3] = dp[i - 1][2];
    }

    return std::max(dp[n - 1][1], std::max(dp[n - 1][2], dp[n - 1][3]));
}

int main(int argc, char *argv[]) {
    std::vector<int> prices{1, 2, 3, 0, 2};

    int res = maxProfit(prices);

    std::cout << res << std::endl;
    return 0;
}
