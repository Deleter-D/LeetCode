/*
    Topic link: https://leetcode.cn/problems/jump-game/
*/
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

bool canJump(std::vector<int> &nums) {
    if (nums.size() == 1)
        return true;

    int cover = 0;
    for (int i = 0; i <= cover; i++) {
        cover = std::max(i + nums[i], cover);
        if (cover >= nums.size() - 1)
            return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{2, 3, 1, 1, 4};

    bool res = canJump(nums);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
