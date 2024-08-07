/*
    Topic link: https://leetcode.cn/problems/unique-paths-ii/
*/
#include "utils/DPUtils.h"
#include <iostream>
#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for (int j = 0; j < n; j++) {
        if (obstacleGrid[0][j] == 1)
            break;
        dp[0][j] = 1;
    }
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1)
            break;
        dp[i][0] = 1;
    }

    printDP(dp);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                printDP(dp);
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    int res = uniquePathsWithObstacles(obstacleGrid);

    std::cout << res << std::endl;
    return 0;
}
