/*
    Topic link: https://leetcode.cn/problems/combination-sum-ii/
*/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> path;
int sum = 0;

void backtracing(std::vector<int> &candidates, int target, int startIdx) {
    if (sum >= target) {
        if (sum == target)
            res.push_back(path);
        return;
    }

    for (int i = startIdx; i < candidates.size(); i++) {
        if (i > startIdx && candidates[i] == candidates[i - 1]) {
            continue;
        }
        path.push_back(candidates[i]);
        sum += candidates[i];
        backtracing(candidates, target, i + 1);
        sum -= candidates[i];
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                              int target) {
    std::sort(candidates.begin(), candidates.end());
    backtracing(candidates, target, 0);
    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    std::vector<std::vector<int>> res = combinationSum2(candidates, target);

    for (auto vec : res) {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
