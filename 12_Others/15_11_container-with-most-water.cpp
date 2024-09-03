/*
    Topic link: https://leetcode.cn/problems/container-with-most-water/
*/
#include <algorithm>
#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int area = std::min(height[left], height[right]) * (right - left);
    while (left < right) {
        if (height[left] < height[right])
            left++;
        else
            right--;

        area = std::max(
            area, (std::min(height[left], height[right]) * (right - left)));
    }

    return area;
}

int main(int argc, char *argv[]) {
    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    int res = maxArea(height);

    std::cout << res << std::endl;
    return 0;
}
