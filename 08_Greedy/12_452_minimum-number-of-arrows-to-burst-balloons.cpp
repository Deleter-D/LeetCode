/*
    Topic link:
   https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int findMinArrowShots(std::vector<std::vector<int>> &points) {
    if (points.size() == 0)
        return 0;
    std::sort(
        points.begin(), points.end(),
        [](std::vector<int> &a, std::vector<int> &b) { return a[0] < b[0]; });

    int arrow = 1;
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > points[i - 1][1])
            arrow++;
        else
            points[i][1] = std::min(points[i - 1][1], points[i][1]);
    }

    return arrow;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    int res = findMinArrowShots(points);

    std::cout << res << std::endl;
    return 0;
}
