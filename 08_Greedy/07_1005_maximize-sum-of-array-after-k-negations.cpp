/*
    Topic link:
   https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int largestSumAfterKNegations(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end(),
              [](int a, int b) { return abs(a) > abs(b); });

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0 && k > 0) {
            nums[i] *= -1;
            k--;
        }
    }

    if (k % 2 == 1)
        nums[nums.size() - 1] *= -1;

    return std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{3, -1, 0, 2};

    int res = largestSumAfterKNegations(nums, 3);

    std::cout << res << std::endl;
    return 0;
}
