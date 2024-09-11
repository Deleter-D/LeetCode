/*
    Topic link: https://leetcode.cn/problems/insert-interval/
*/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                     std::vector<int> &newInterval) {
    std::vector<std::vector<int>> res;

    bool placed = false;

    for (auto &interval : intervals) {
        if (interval[0] > newInterval[1]) {
            if (!placed) {
                res.push_back(newInterval);
                placed = true;
            }
            res.push_back(interval);
        } else if (interval[1] < newInterval[0]) {
            res.push_back(interval);
        } else {
            newInterval = {std::min(newInterval[0], interval[0]),
                           std::max(newInterval[1], interval[1])};
        }
    }

    if (!placed) {
        res.push_back(newInterval);
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> intervals{
        {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};

    std::vector<int> newInterval{4, 8};

    auto res = insert(intervals, newInterval);

    for (auto vec : res) {
        for (int i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
