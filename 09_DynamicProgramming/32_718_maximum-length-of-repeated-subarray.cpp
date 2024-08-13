/*
    Topic link:
   https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
*/
#include <iostream>
#include <vector>

int findLength(std::vector<int> &nums1, std::vector<int> &nums2) {
    int res = 0;

    std::vector<std::vector<int>> dp(nums1.size() + 1,
                                     std::vector<int>(nums2.size() + 1, 0));

    for (int i = 1; i <= nums1.size(); i++) {
        for (int j = 1; j <= nums2.size(); j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if (dp[i][j] > res)
                res = dp[i][j];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums1{1, 2, 3, 2, 1};
    std::vector<int> nums2{3, 2, 1, 4, 7};

    int res = findLength(nums1, nums2);

    std::cout << res << std::endl;
    return 0;
}
