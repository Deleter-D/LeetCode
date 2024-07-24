/*
    Topic link: https://leetcode.cn/problems/non-decreasing-subsequences/
*/
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> path;

void backtracking(std::vector<int> &nums, int startIdx) {
    if (path.size() > 1)
        res.push_back(path);

    if (startIdx >= nums.size())
        return;

    std::unordered_set<int> used;
    for (int i = startIdx; i < nums.size(); i++) {
        if ((!path.empty() && nums[i] < path.back()) ||
            used.find(nums[i]) != used.end())
            continue;
        used.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums) {
    backtracking(nums, 0);
    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{4, 6, 7, 7};

    auto res = findSubsequences(nums);

    for (auto vec : res) {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}
