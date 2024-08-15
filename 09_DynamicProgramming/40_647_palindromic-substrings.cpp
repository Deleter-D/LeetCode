/*
    Topic link: https://leetcode.cn/problems/palindromic-substrings/
*/
#include <iostream>
#include <string>
#include <vector>

int countSubstrings(std::string s) {
    std::vector<std::vector<bool>> dp(s.size(),
                                      std::vector<bool>(s.size(), false));

    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1) {
                    res++;
                    dp[i][j] = true;
                } else if (dp[i + 1][j - 1]) {
                    res++;
                    dp[i][j] = true;
                }
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string s("aaa");

    int res = countSubstrings(s);

    std::cout << res << std::endl;
    return 0;
}
