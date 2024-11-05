/*
    Topic link: https://leetcode.cn/problems/longest-palindromic-substring/
*/
#include <iostream>
#include <string>
#include <vector>

std::string longestPalindrome(std::string s) {
    std::vector<std::vector<bool>> dp(s.size(),
                                      std::vector<bool>(s.size(), false));

    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
    }

    int maxLen = 1;
    int begin = 0;
    for (int len = 2; len <= s.size(); len++) {
        for (int left = 0; left < s.size(); left++) {
            int right = len + left - 1;
            if (right >= s.size()) {
                break;
            }

            if (s[left] != s[right]) {
                dp[left][right] = false;
            } else {
                if (right - left < 3) {
                    dp[left][right] = true;
                } else {
                    dp[left][right] = dp[left + 1][right - 1];
                }
            }

            if (dp[left][right] && right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                begin = left;
            }
        }
    }

    return s.substr(begin, maxLen);
}

int main(int argc, char const *argv[]) {
    std::string s("babad");

    std::string res = longestPalindrome(s);

    std::cout << res << std::endl;
    return 0;
}
