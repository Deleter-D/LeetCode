/*
    Topic link:
   https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
*/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() <= 2)
        return nums.size();

    int slow = 2;
    int fast = 2;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow - 2]) {
            nums[slow++] = nums[fast];
        }
        fast++;
    }

    return slow;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};

    int k = removeDuplicates(nums);

    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
