/*
    Topic link: https://leetcode.cn/problems/merge-intervals/
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
    std::sort(
        intervals.begin(), intervals.end(),
        [](std::vector<int> &a, std::vector<int> &b) { return a[0] < b[0]; });

    std::vector<std::vector<int>> res;
    std::vector<int> tmp(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= tmp[1]) {
            tmp[1] = std::max(intervals[i][1], tmp[1]);
        } else {
            res.push_back(tmp);
            tmp = intervals[i];
        }
    }
    res.push_back(tmp);

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    auto res = merge(intervals);

    for (auto vec : res) {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
