/*
    Topic link: https://leetcode.cn/problems/maximum-subarray/
*/
#include <climits>
#include <iostream>
#include <ostream>
#include <vector>

int maxSubArray(std::vector<int> &nums) {
    int res = INT_MIN;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum > res)
            res = sum;
        if (sum <= 0)
            sum = 0;
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int res = maxSubArray(nums);

    std::cout << res << std::endl;
    return 0;
}
