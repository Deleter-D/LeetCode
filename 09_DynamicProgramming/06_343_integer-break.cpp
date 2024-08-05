/*
    Topic link: https://leetcode.cn/problems/integer-break/
*/
#include "utils/DPUtils.h"
#include <algorithm>
#include <iostream>
#include <vector>

int integerBreak(int n) {
    std::vector<int> dp(n + 1);

    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
            printDP(dp);
        }
    }

    return dp[n];
}

int main(int argc, char *argv[]) {
    int res = integerBreak(4);

    std::cout << res << std::endl;

    return 0;
}
