/*
    Topic link: https://leetcode.cn/problems/isomorphic-strings/
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

bool isIsomorphic(std::string s, std::string t) {

    std::unordered_set<char> sset, tset;
    for (int i = 0; i < s.size(); i++) {
        sset.insert(s[i]);
        tset.insert(t[i]);
    }

    if (tset.size() < sset.size()) {
        std::string tmp = s;
        s = t;
        t = tmp;
    }

    std::unordered_map<char, char> umap;
    for (int i = 0; i < s.size(); i++) {
        auto iter = umap.find(s[i]);
        if (iter != umap.end()) {
            if (t[i] != iter->second) {
                return false;
            }
        } else {
            umap[s[i]] = t[i];
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    std::string s("paper");
    std::string t("title");

    bool res = isIsomorphic(s, t);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
