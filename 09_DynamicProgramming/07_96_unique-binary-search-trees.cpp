/*
    Topic link: https://leetcode.cn/problems/unique-binary-search-trees/
*/
#include <iostream>
#include <vector>

int numTrees(int n) {
    std::vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}

int main(int argc, char *argv[]) {
    int res = numTrees(5);

    std::cout << res << std::endl;
    return 0;
}
