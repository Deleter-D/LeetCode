/*
    Topic link: https://leetcode.cn/problems/restore-ip-addresses/
*/
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> res;

bool isValid(std::string &s, int begin, int end) {
    if (begin > end) {
        return false;
    }
    if (s[begin] == '0' && begin != end) {
        return false;
    }
    int num = 0;
    for (int i = begin; i <= end; i++) {
        if (s[i] > '9' || s[i] < '0') {
            return false;
        }
        num = num * 10 + (s[i] - '0');
        if (num > 255) {
            return false;
        }
    }
    return true;
}

void backtracking(std::string &s, int startIdx, int pointNum) {
    if (pointNum == 3) {
        if (isValid(s, startIdx, s.size() - 1))
            res.push_back(s);
        return;
    }

    for (int i = startIdx; i < s.size(); i++) {
        if (isValid(s, startIdx, i)) {
            s.insert(s.begin() + i + 1, '.');
            backtracking(s, i + 2, pointNum + 1);
            s.erase(s.begin() + i + 1);
        } else {
            break;
        }
    }
}

std::vector<std::string> restoreIpAddresses(std::string s) {
    backtracking(s, 0, 0);
    return res;
}

int main(int argc, char *argv[]) {
    std::string s("25525511135");

    std::vector<std::string> res = restoreIpAddresses(s);

    for (auto str : res) {
        std::cout << str << std::endl;
    }

    return 0;
}
