/*
    Topic link: https://leetcode.cn/problems/longest-common-prefix/
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::string &str1, std::string &str2) {
    int len = std::min(str1.size(), str2.size());
    int idx = 0;

    while (idx < len && str1[idx] == str2[idx]) {
        idx++;
    }

    return str1.substr(0, idx);
}

std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.size() == 0)
        return "";

    std::string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        prefix = longestCommonPrefix(prefix, strs[i]);
        if (prefix.size() == 0)
            break;
    }

    return prefix;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> strs{"flower", "flow", "flight"};

    std::string res = longestCommonPrefix(strs);

    std::cout << res << std::endl;
    return 0;
}
