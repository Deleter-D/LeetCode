/*
    Topic link: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
*/
#include <iostream>
#include <vector>

int maxProfit(int k, std::vector<int> &prices) {
    std::vector<std::vector<int>> dp(prices.size(),
                                     std::vector<int>(k * 2 + 1, 0));

    for (int i = 0; i < k * 2 + 1; i++) {
        if (i % 2 == 0)
            dp[0][i] = 0; // the kth time don't hold stocks
        else
            dp[0][i] = -prices[0]; // the kth time hold stocks
    }

    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j < k * 2 + 1; j++) {
            if (j % 2 != 0)
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            else

                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
        }
    }

    return dp[prices.size() - 1][k * 2];
}

int main(int argc, char *argv[]) {
    std::vector<int> prices{3, 2, 6, 5, 0, 3};
    int k = 2;

    int res = maxProfit(k, prices);

    std::cout << res << std::endl;
    return 0;
}
