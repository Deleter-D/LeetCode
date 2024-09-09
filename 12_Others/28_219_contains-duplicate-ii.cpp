/*
    Topic link: https://leetcode.cn/problems/contains-duplicate-ii/
*/
#include <iostream>
#include <unordered_map>
#include <vector>

bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i++) {
        if (umap.find(nums[i]) != umap.end() && abs(i - umap[nums[i]]) <= k) {
            return true;
        } else {
            umap[nums[i]] = i;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 0, 1, 1};
    int k = 1;

    bool res = containsNearbyDuplicate(nums, k);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
