/*
    Topic link: https://leetcode.cn/problems/interleaving-string/
*/
#include <iostream>
#include <string>
#include <vector>

bool isInterleave(std::string s1, std::string s2, std::string s3) {
    std::vector<std::vector<bool>> dp(s1.size() + 1,
                                      std::vector<bool>(s2.size() + 1, false));

    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }

    dp[0][0] = true;
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i > 0) {
                dp[i][j] =
                    dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            }
            if (j > 0) {
                dp[i][j] =
                    dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

int main(int argc, char const *argv[]) {
    std::string s1("aabcc");
    std::string s2("dbbca");
    std::string s3("aadbbcbcac");

    bool res = isInterleave(s1, s2, s3);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
