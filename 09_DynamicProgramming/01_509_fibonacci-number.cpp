/*
        Topic link: https://leetcode.cn/problems/fibonacci-number/
*/
#include <iostream>
#include <vector>

int fib(int n) {
    if (n <= 1)
        return n;

    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(int argc, char *argv[]) {
    int res = fib(4);

    std::cout << res << std::endl;
    return 0;
}
