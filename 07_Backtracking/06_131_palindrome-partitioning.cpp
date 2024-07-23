/*
    https://leetcode.cn/problems/palindrome-partitioning/
*/
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> res;
std::vector<std::string> path;

bool isPalindrome(std::string &str, int begin, int end) {
    for (int i = begin, j = end; i < j; i++, j--) {
        if (str[i] != str[j])
            return false;
    }
    return true;
}

void backtracking(std::string &s, int startIdx) {
    if (startIdx >= s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = startIdx; i < s.size(); i++) {
        if (isPalindrome(s, startIdx, i)) {
            path.push_back(s.substr(startIdx, i - startIdx + 1));
        } else {
            continue;
        }
        backtracking(s, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<std::string>> partition(std::string s) {
    backtracking(s, 0);
    return res;
}

int main(int argc, char *argv[]) {
    std::string s("aab");

    std::vector<std::vector<std::string>> res = partition(s);

    for (auto vec : res) {
        for (auto s : vec)
            std::cout << s << " ";
        std::cout << std::endl;
    }
    return 0;
}
