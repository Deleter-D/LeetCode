/*
    Topic link: https://leetcode.cn/problems/minimum-size-subarray-sum/
*/
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

// sliding windows solution
int minSubArrayLen(int target, vector<int> &nums) {
    int slow = 0, fast = 0;
    int sum = 0;
    int minlen = INT32_MAX;
    for (; fast < nums.size(); fast++) {
        sum += nums[fast]; // 滑动窗口不断扩大，并将加入窗口的元素累加到sum中
        while (sum >= target) { // 当窗口中的元素和满足条件后
            if ((fast - slow + 1) < minlen)
                minlen = fast - slow + 1; // 记录当前滑动窗口的大小
            sum -= nums[slow]; // 将滑动窗口的左侧缩小一个元素
            slow++;
        }
    }

    if (minlen == INT32_MAX)
        return 0;
    else
        return minlen;
}

int main(int argc, char *argv[]) {
    vector<int> nums{2, 3, 1, 2, 4, 3};
    int res = minSubArrayLen(7, nums);
    cout << res << endl;
    return 0;
}
