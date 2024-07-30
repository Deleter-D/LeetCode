/*
    Topic link: https://leetcode.cn/problems/non-overlapping-intervals/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
    if (intervals.empty())
        return 0;
    std::sort(
        intervals.begin(), intervals.end(),
        [](std::vector<int> &a, std::vector<int> &b) { return a[1] < b[1]; });

    int count = 1;
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (end <= intervals[i][0]) {
            end = intervals[i][1];
            count++;
        }
    }

    return intervals.size() - count;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    int res = eraseOverlapIntervals(intervals);

    std::cout << res << std::endl;
    return 0;
}
