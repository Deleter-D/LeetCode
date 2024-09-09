/*
    Topic link: https://leetcode.cn/problems/longest-consecutive-sequence/
*/
#include <iostream>
#include <unordered_set>
#include <vector>

int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> uset;
    for (int &num : nums) {
        uset.insert(num);
    }

    int longestStreak = 0;

    for (auto &num : nums) {
        if (!uset.count(num - 1)) {
            int curNum = num;
            int curStreak = 1;

            while (uset.count(curNum + 1)) {
                curNum += 1;
                curStreak += 1;
            }

            longestStreak = std::max(longestStreak, curStreak);
        }
    }

    return longestStreak;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    int res = longestConsecutive(nums);

    std::cout << res << std::endl;
    return 0;
}
