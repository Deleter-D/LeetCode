/*
    Topic link: https://leetcode.cn/problems/distinct-subsequences/
*/
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int numDistinct(std::string s, std::string t) {
    std::vector<std::vector<int>> dp(s.size() + 1,
                                     std::vector<int>(t.size() + 1));

    int tmp = static_cast<int>(pow(10, 9) + 7);

    for (int i = 0; i <= s.size(); i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= t.size(); j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] % tmp + dp[i - 1][j] % tmp;
            else
                dp[i][j] = dp[i - 1][j] % tmp;
        }
    }

    return dp[s.size()][t.size()];
}

int main(int argc, char *argv[]) {
    std::string s("babgbag");
    std::string t("bag");

    int res = numDistinct(s, t);

    std::cout << res << std::endl;
    return 0;
}
