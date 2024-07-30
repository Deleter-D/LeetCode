/*
    Topic link: https://leetcode.cn/problems/partition-labels/
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> partitionLabels(std::string s) {
    std::unordered_map<char, int> record;

    for (int i = 0; i < s.size(); i++)
        record[s[i]] = i;

    std::vector<int> res;
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); i++) {
        right = std::max(right, record[s[i]]);
        if (i == right) {
            res.push_back(right - left + 1);
            left = i + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string s("ababcbacadefegdehijhklij");

    auto res = partitionLabels(s);

    for (auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
