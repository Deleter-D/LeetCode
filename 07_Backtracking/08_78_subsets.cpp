/*
    Topic link: https://leetcode.cn/problems/subsets/
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> path;

void backtracking(std::vector<int> &nums, int startIdx) {
    res.push_back(path);
    if (startIdx >= nums.size()) {
        return;
    }

    for (int i = startIdx; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    backtracking(nums, 0);
    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 2, 3};
    auto res = subsets(nums);

    for (auto vec : res) {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
