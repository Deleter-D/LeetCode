/*
    Topic link: https://leetcode.cn/problems/subsets-ii/
*/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> path;

void backtracking(std::vector<int> &nums, int startIdx,
                  std::vector<bool> used) {
    res.push_back(path);
    if (startIdx >= nums.size()) {
        return;
    }

    for (int i = startIdx; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, i + 1, used);
        used[i] = false;
        path.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<bool> used(nums.size(), false);
    backtracking(nums, 0, used);
    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 2, 2};
    auto res = subsetsWithDup(nums);

    for (auto vec : res) {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
