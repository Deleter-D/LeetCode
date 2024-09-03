/*
    Topic link: https://leetcode.cn/problems/minimum-window-substring/
*/
#include <iostream>
#include <string>
#include <unordered_map>

bool check(std::unordered_map<char, int> &smap,
           std::unordered_map<char, int> &tmap) {
    for (auto iter : tmap) {
        if (iter.second > smap[iter.first]) {
            return false;
        }
    }
    return true;
}

std::string minWindow(std::string s, std::string t) {
    std::string res = "";
    int sl = s.size();
    int tl = t.size();

    if (sl < tl)
        return res;

    std::unordered_map<char, int> smap, tmap;

    for (int i = 0; i < tl; i++) {
        tmap[t[i]]++;
    }

    int left = 0, right = 0;
    int resBegin = -1;
    int windowSize = INT_MAX;
    while (right < sl) {
        smap[s[right]]++;

        if (tmap.find(s[right]) != tmap.end()) {
            while (check(smap, tmap) && left <= right) {
                if (right - left + 1 < windowSize) {
                    resBegin = left;
                    windowSize = right - left + 1;
                }
                smap[s[left]]--;
                left++;
            }
        }

        right++;
    }

    if (resBegin == -1)
        return "";

    return s.substr(resBegin, windowSize);
}

int main(int argc, char *argv[]) {
    std::string s("ADOBECODEBANC");
    std::string t("ABC");

    std::string res = minWindow(s, t);

    std::cout << res << std::endl;
    return 0;
}
