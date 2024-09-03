/*
    Topic link: https://leetcode.cn/problems/find-all-anagrams-in-a-string/
*/
#include <iostream>
#include <string>
#include <vector>

std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> res;

    if (s.size() < p.size())
        return res;

    std::vector<int> scount(26, 0);
    std::vector<int> pcount(26, 0);
    for (int i = 0; i < p.size(); i++) {
        scount[s[i] - 'a']++;
        pcount[p[i] - 'a']++;
    }

    if (scount == pcount) {
        res.push_back(0);
    }

    for (int i = 0; i < s.size() - p.size(); i++) {
        scount[s[i] - 'a']--;
        scount[s[i + p.size()] - 'a']++;

        if (scount == pcount) {
            res.push_back(i + 1);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string s("cbaebabacd");
    std::string p("abc");

    auto res = findAnagrams(s, p);

    for (auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
