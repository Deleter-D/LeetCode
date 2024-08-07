/*
    Topic link: https://leetcode.cn/problems/coin-change/
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int coinChange(std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX)
                dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main(int argc, char *argv[]) {
    std::vector<int> coins{1, 2, 5};
    int amount = 11;

    int res = coinChange(coins, amount);

    std::cout << res << std::endl;
    return 0;
}
