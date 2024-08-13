/*
    Topic link: https://leetcode.cn/problems/is-subsequence/
*/
#include <iostream>
#include <string>
#include <vector>

bool isSubsequence(std::string s, std::string t) {
    std::vector<std::vector<int>> dp(s.size() + 1,
                                     std::vector<int>(t.size() + 1, 0));

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[s.size()][t.size()] == s.size() ? true : false;
}

int main(int argc, char *argv[]) {
    std::string s("abc");
    std::string t("ahbgdc");

    bool res = isSubsequence(s, t);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
