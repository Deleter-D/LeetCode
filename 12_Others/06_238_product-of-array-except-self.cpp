/*
    Topic link: https://leetcode.cn/problems/product-of-array-except-self/
*/
#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> left(nums.size());
    std::vector<int> right(nums.size());

    left[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[nums.size() - 1] = 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = left[i] * right[i];
    }

    return nums;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 2, 3, 4};

    auto res = productExceptSelf(nums);

    for (auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
