/*
    Topic link: https://leetcode.cn/problems/jump-game-ii/
*/
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

int jump(std::vector<int> &nums) {
    if (nums.size() == 1)
        return 0;

    int res = 0;

    int curCover = 0;
    int nextCover = 0;
    for (int i = 0; i < nums.size(); i++) {
        nextCover = std::max(nums[i] + i, nextCover);
        if (i == curCover) {
            res++;
            curCover = nextCover;
            if (nextCover >= nums.size() - 1)
                break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{2, 3, 1, 1, 4};

    int res = jump(nums);

    std::cout << res << std::endl;
    return 0;
}
