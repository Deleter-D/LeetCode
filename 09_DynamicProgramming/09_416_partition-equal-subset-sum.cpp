/*
    Topic link: https://leetcode.cn/problems/partition-equal-subset-sum/
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

bool canPartition(std::vector<int> &nums) {
    std::vector<int> dp(10001, 0);

    int sum = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());

    if (sum % 2 != 0)
        return false;

    int target = sum / 2;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    if (dp[target] == target)
        return true;

    return false;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 5, 11, 5};

    bool res = canPartition(nums);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
