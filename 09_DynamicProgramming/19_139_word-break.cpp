/*
    Topic link: https://leetcode.cn/problems/word-break/
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

    std::vector<bool> dp(s.size() + 1, false);

    dp[0] = true;
    for (int j = 1; j <= s.size(); j++) {
        for (int i = 0; i < j; i++) {
            std::string word = s.substr(i, j - i);
            if (wordSet.find(word) != wordSet.end() && dp[i])
                dp[j] = true;
        }
    }

    return dp[s.size()];
}

int main(int argc, char *argv[]) {
    std::vector<std::string> wordDict{"apple", "pen"};
    std::string s = "applepenapple";

    bool res = wordBreak(s, wordDict);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
