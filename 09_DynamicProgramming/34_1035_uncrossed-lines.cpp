/*
    Topic link: https://leetcode.cn/problems/uncrossed-lines/
*/
#include <iostream>
#include <vector>

int maxUncrossedLines(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<std::vector<int>> dp(nums1.size() + 1,
                                     std::vector<int>(nums2.size() + 1, 0));

    for (int i = 1; i <= nums1.size(); i++) {
        for (int j = 1; j <= nums2.size(); j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[nums1.size()][nums2.size()];
}

int main(int argc, char *argv[]) {
    std::vector<int> nums1{1, 3, 7, 1, 7, 5};
    std::vector<int> nums2{1, 9, 2, 5, 1};

    int res = maxUncrossedLines(nums1, nums2);

    std::cout << res << std::endl;
    return 0;
}
