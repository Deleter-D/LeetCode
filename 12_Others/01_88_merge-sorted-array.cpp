/*
        Topic link: https://leetcode.cn/problems/merge-sorted-array/
*/
#include <iostream>
#include <vector>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int idx = m + n - 1;
    int i = m - 1, j = n - 1;
    while (i >= 0 || j >= 0) {
        if (i == -1) {
            nums1[idx] = nums2[j--];
        } else if (j == -1) {
            nums1[idx] = nums1[i--];
        } else if (nums1[i] >= nums2[j]) {
            nums1[idx] = nums1[i--];
        } else {
            nums1[idx] = nums2[j--];
        }
        idx--;
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> nums1{2, 0};
    int m = 1;
    std::vector<int> nums2{1};
    int n = 1;

    merge(nums1, m, nums2, n);
    return 0;
}
