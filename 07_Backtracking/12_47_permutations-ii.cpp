/*
    Topic link: https://leetcode.cn/problems/permutations-ii/
*/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> path;

void backtracking(std::vector<int> &nums, std::vector<bool> &used) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i] == true)
            continue;
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            continue;
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, used);
        used[i] = false;
        path.pop_back();
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 1, 2};

    auto res = permuteUnique(nums);

    for (auto vec : res) {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
