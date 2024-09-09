/*
    Topic link: https://leetcode.cn/problems/word-pattern/
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> split(std::string &s, char delimiter) {
    std::vector<std::string> vec;
    std::string word("");
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == delimiter && !word.empty()) {
            vec.push_back(word);
            word = "";
        } else {
            word += s[i];
        }
    }

    if (!word.empty()) {
        vec.push_back(word);
    }

    return vec;
}

bool wordPattern(std::string pattern, std::string s) {
    auto words = split(s, ' ');

    if (pattern.size() != words.size())
        return false;

    std::unordered_map<char, std::string> pattern_map;
    std::unordered_map<std::string, char> s_map;
    for (int i = 0; i < pattern.size(); i++) {
        auto p_iter = pattern_map.find(pattern[i]);
        auto s_iter = s_map.find(words[i]);
        if (p_iter != pattern_map.end() && s_iter != s_map.end()) {
            if (words[i] != p_iter->second || pattern[i] != s_iter->second) {
                return false;
            }
        } else if (p_iter != pattern_map.end()) {
            if (words[i] != p_iter->second) {
                return false;
            }
        } else if (s_iter != s_map.end()) {
            if (pattern[i] != s_map[words[i]]) {
                return false;
            }
        } else {
            pattern_map[pattern[i]] = words[i];
            s_map[words[i]] = pattern[i];
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    std::string pattern("abba");
    std::string s("dog dog dog dog");

    bool res = wordPattern(pattern, s);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
