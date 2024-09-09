/*
    Topic link: https://leetcode.cn/problems/group-anagrams/
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::vector<std::string>>
groupAnagrams(std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> res;

    std::unordered_map<std::string, std::vector<std::string>> umap;
    for (auto str : strs) {
        std::string key = str;
        std::sort(key.begin(), key.end());
        umap[key].push_back(str);
    }

    for (auto iter = umap.begin(); iter != umap.end(); iter++) {
        res.push_back(iter->second);
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    auto res = groupAnagrams(strs);

    for (auto vec : res) {
        for (auto s : vec) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
