/*
    Topic link:
   https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
*/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() <= 1)
        return nums.size();

    int slow = 0;
    int fast = 1;
    while (fast < nums.size()) {
        if (nums[fast] == nums[slow]) {
            fast++;
        } else {
            nums[++slow] = nums[fast++];
        }
    }

    return slow;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums);

    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
