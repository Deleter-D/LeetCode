/*
    Topic link: https://kamacoder.com/problempage.php?pid=1067
*/
#include <iostream>
#include <vector>

int climbStairs(int n, int m) {
    std::vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (j - i >= 0)
                dp[j] += dp[j - i];
        }
    }

    return dp[n];
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int res = climbStairs(n, m);

    std::cout << res << std::endl;
}
