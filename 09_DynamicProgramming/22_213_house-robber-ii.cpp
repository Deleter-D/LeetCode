/*
    Topic link: https://leetcode.cn/problems/house-robber-ii/
*/
#include <iostream>
#include <vector>

int rob(std::vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return std::max(nums[0], nums[1]);

    std::vector<int> dp1(nums.size(), 0);
    std::vector<int> dp2(nums.size(), 0);

    dp1[0] = nums[0];
    dp1[1] = std::max(nums[0], nums[1]);

    dp2[1] = nums[1];
    dp2[2] = std::max(nums[1], nums[2]);

    for (int i = 2; i < nums.size() - 1; i++) {
        dp1[i] = std::max(dp1[i - 2] + nums[i], dp1[i - 1]);
    }

    for (int i = 3; i < nums.size(); i++) {
        dp2[i] = std::max(dp2[i - 2] + nums[i], dp2[i - 1]);
    }

    return std::max(dp1[nums.size() - 2], dp2[nums.size() - 1]);
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 2, 1, 1};

    int res = rob(nums);

    std::cout << res << std::endl;
    return 0;
}
