/*
    Topic link: https://leetcode.cn/problems/minimum-path-sum/
*/
#include <iostream>
#include <vector>

int minPathSum(std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<int>> dp(grid.size(),
                                     std::vector<int>(grid[0].size(), 0));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < grid.size(); i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < grid[0].size(); j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[0].size(); j++) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[grid.size() - 1][grid[0].size() - 1];
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    int res = minPathSum(grid);

    std::cout << res << std::endl;
    return 0;
}
