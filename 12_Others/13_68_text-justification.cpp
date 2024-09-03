/*
    Topic link: https://leetcode.cn/problems/text-justification/
*/
#include <climits>
#include <iostream>
#include <string>
#include <vector>

std::string blank(int n) { return std::string(n, ' '); }

std::string join(std::vector<std::string> &words, int left, int right,
                 std::string sep) {
    std::string res = words[left];
    for (int i = left + 1; i < right; i++) {
        res += sep + words[i];
    }
    return res;
}

std::vector<std::string> fullJustify(std::vector<std::string> &words,
                                     int maxWidth) {
    std::vector<std::string> res;
    int n = words.size();

    int right = 0;
    while (true) {
        int left = right;
        int lineLen = 0;
        while (right < n &&
               lineLen + words[right].size() + right - left <= maxWidth) {
            lineLen += words[right++].size();
        }

        if (right == n) {
            std::string s = join(words, left, n, " ");
            res.push_back(s + blank(maxWidth - s.size()));
            return res;
        }

        int numWords = right - left;
        int numSpaces = maxWidth - lineLen;

        if (numWords == 1) {
            res.push_back(words[left] + blank(numSpaces));
        } else {
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            std::string s1 =
                join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1));
            std::string s2 =
                join(words, left + extraSpaces + 1, right, blank(avgSpaces));
            res.push_back(s1 + blank(avgSpaces) + s2);
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::string> words{
        "Science", "is", "what",       "we",   "understand", "well",
        "enough",  "to", "explain",    "to",   "a",          "computer.",
        "Art",     "is", "everything", "else", "we",         "do"};
    int maxWidth = 20;

    auto res = fullJustify(words, maxWidth);

    for (auto str : res) {
        std::cout << str << std::endl;
    }
    return 0;
}
