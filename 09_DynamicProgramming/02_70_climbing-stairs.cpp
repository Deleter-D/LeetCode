/*
    Topic link: https://leetcode.cn/problems/climbing-stairs/
*/
#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n <= 1)
        return n;

    std::vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(int argc, char *argv[]) {
    int res = climbStairs(3);

    std::cout << res << std::endl;
    return 0;
}
