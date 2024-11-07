/*
    Topic link: https://leetcode.cn/problems/maximal-square/
*/
#include <iostream>
#include <vector>

int maximalSquare(std::vector<std::vector<char>> &matrix) {
    std::vector<std::vector<int>> dp(matrix.size(),
                                     std::vector<int>(matrix[0].size(), 0));

    int maxSide = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]),
                                        dp[i - 1][j - 1]) +
                               1;
                }
                if (dp[i][j] > maxSide) {
                    maxSide = dp[i][j];
                }
            }
        }
    }

    return maxSide * maxSide;
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                          {'1', '0', '1', '1', '1'},
                                          {'1', '1', '1', '1', '1'},
                                          {'1', '0', '0', '1', '0'}};

    int res = maximalSquare(matrix);

    std::cout << res << std::endl;
    return 0;
}