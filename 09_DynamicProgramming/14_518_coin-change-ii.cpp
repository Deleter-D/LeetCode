/*
    Topic link: https://leetcode.cn/problems/coin-change-ii/
*/
#include <iostream>
#include <vector>

int change(int amount, std::vector<int> &coins) {
    std::vector<int> dp(amount + 1, 0);

    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main(int argc, char *argv[]) {
    std::vector<int> coins{1, 2, 5};
    int amount = 5;

    int res = change(amount, coins);

    std::cout << res << std::endl;
    return 0;
}
