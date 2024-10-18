#include <climits>
#include <iostream>
#include <vector>

int minimumTotal(std::vector<std::vector<int>> &triangle) {

    std::vector<std::vector<int>> dp(triangle.size());
    for (int i = 0; i < triangle.size(); i++) {
        dp[i] = std::vector<int>(triangle[i].size(), 0);
    }

    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            } else if (j == triangle[i].size() - 1) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            } else {
                int left_parent = (j + j + 1) / 2 - 1;
                int right_parent = left_parent + 1;
                dp[i][j] = std::min(dp[i - 1][left_parent] + triangle[i][j],
                                    dp[i - 1][right_parent] + triangle[i][j]);
            }
        }
    }

    int res = INT_MAX;
    for (auto &i : dp[dp.size() - 1]) {
        res = std::min(res, i);
    }

    return res;
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> triangle{
        {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    int res = minimumTotal(triangle);

    std::cout << res << std::endl;
    return 0;
}
