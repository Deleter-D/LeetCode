/*
    Topic link: https://leetcode.cn/problems/perfect-squares/
*/
#include "utils/DPUtils.h"
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int numSquares(int n) {
    int len = static_cast<int>(std::sqrt(n));
    std::vector<int> item(len);

    for (int i = 1; i <= len; i++)
        item[i - 1] = i * i;

    std::vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 0; i < item.size(); i++) {
        for (int j = item[i]; j <= n; j++) {
            if (dp[j - item[i]] != INT_MAX)
                dp[j] = std::min(dp[j], dp[j - item[i]] + 1);
            printDP(dp);
        }
    }

    return dp[n];
}

int main(int argc, char *argv[]) {
    int n = 12;

    int res = numSquares(n);

    std::cout << res << std::endl;
    return 0;
}
