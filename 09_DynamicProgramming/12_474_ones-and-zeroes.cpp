/*
    Topic link: https://leetcode.cn/problems/ones-and-zeroes/
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int findMaxForm(std::vector<std::string> &strs, int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (std::string str : strs) {
        int oneCount = 0, zeroCount = 0;
        for (char c : str) {
            if (c == '0')
                zeroCount++;
            else
                oneCount++;
        }
        for (int i = m; i >= zeroCount; i--) {
            for (int j = n; j >= oneCount; j--) {
                dp[i][j] =
                    std::max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
            }
        }
    }

    return dp[m][n];
}

int main(int argc, char *argv[]) {
    std::vector<std::string> strs{"10", "0001", "111001", "1", "0"};

    int res = findMaxForm(strs, 5, 3);

    std::cout << res << std::endl;
    return 0;
}
