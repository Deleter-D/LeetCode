/*
    Topic link: https://leetcode.cn/problems/4sum/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        // 第一层剪枝，但不能简单的因为nums[i] > target就剪枝
        if (nums[i] > target && nums[i] >= 0)
            break;
        // 对四元组第一个元素去重
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size(); j++) {
            // 第二层剪枝，条件判断与第一层同理
            if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                break;

            // 对四元组第二个元素去重
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right) {
                // 用long类型防止溢出
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // 对四元组第三个元素去重
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    // 对四元组第四个元素去重
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    left++;
                    right--;
                }
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    for (vector<int> vec : res) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
