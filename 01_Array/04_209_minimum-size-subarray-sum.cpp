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
        sum += nums[fast];
        while (sum >= target) {
            if ((fast - slow + 1) < minlen)
                minlen = fast - slow + 1;
            sum -= nums[slow];
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
