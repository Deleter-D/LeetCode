/*
    Topic link: https://leetcode.cn/problems/summary-ranges/
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> summaryRanges(std::vector<int> &nums) {
    std::vector<std::string> res;

    if (nums.size() == 0) {
        return res;
    }

    int left = 0, right = 0;
    while (right < nums.size()) {
        int leftNum = nums[left];
        int tmp = leftNum;

        while (right + 1 < nums.size() && nums[right + 1] == tmp + 1) {
            right++;
            tmp++;
        }

        std::ostringstream oss;
        if (leftNum == tmp) {
            oss << leftNum;
        } else {
            oss << leftNum << "->" << tmp;
        }
        res.push_back(oss.str());

        left = right + 1;
        right = left;
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{0, 1, 2, 4, 5, 7};

    auto res = summaryRanges(nums);

    for (auto &str : res) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}
