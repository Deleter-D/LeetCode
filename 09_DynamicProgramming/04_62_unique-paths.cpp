/*
    Topic link: https://leetcode.cn/problems/unique-paths/
*/
#include "utils/DPUtils.h"
#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {

    std::vector<std::vector<int>> dp(m, std::vector<int>(n));

    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    printDP(dp);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            printDP(dp);
        }
    }

    return dp[m - 1][n - 1];
}

int main(int argc, char *argv[]) {
    int res = uniquePaths(3, 2);

    std::cout << res << std::endl;
    return 0;
}
