/*
        Topic link: https://leetcode.cn/problems/assign-cookies/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int i = 0, j = 0;
    int count = 0;
    while (i < g.size() && j < s.size()) {
        int cookie = 0;
        cookie += s[j];
        j++;
        if (cookie >= g[i]) {
            count++;
            i++;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    std::vector<int> g{1, 2, 3};
    std::vector<int> s{1, 1};

    auto res = findContentChildren(g, s);

    std::cout << res << std::endl;
    return 0;
}
