/*
    Topic link: https://leetcode.cn/problems/delete-operation-for-two-strings/
*/
#include <iostream>
#include <string>
#include <vector>

int minDistance(std::string word1, std::string word2) {
    std::vector<std::vector<int>> dp(word1.size() + 1,
                                     std::vector<int>(word2.size() + 1));

    for (int i = 0; i <= word1.size(); i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= word2.size(); j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] =
                    std::min(std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                             dp[i - 1][j - 1] + 2);
        }
    }

    return dp[word1.size()][word2.size()];
}

int main(int argc, char *argv[]) {
    std::string word1("leetcode");
    std::string word2("etco");

    int res = minDistance(word1, word2);

    std::cout << res << std::endl;
    return 0;
}
