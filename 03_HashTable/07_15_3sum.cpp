/*
    Topic link: https://leetcode.cn/problems/3sum/
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        // 若排序之后的第一个元素已经大于0，则不可能有满足条件的三元组
        if (nums[i] > 0)
            break;
        // 三元组第一个元素去重
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        unordered_set<int> record;
        for (int j = i + 1; j < nums.size(); j++) {
            // 三元组第二个元素去重
            if (j > i + 2 && nums[j] == nums[j - 1] &&
                nums[j - 1] == nums[j - 2])
                continue;

            int c = 0 - (nums[i] + nums[j]);
            if (record.find(c) != record.cend()) {
                res.push_back({nums[i], nums[j], c});
                // 三元组第三个元素去重
                record.erase(c);
            } else {
                record.insert(nums[j]);
            }
        }
    }

    return res;
}

vector<vector<int>> threeSum2(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            break;
        // 三元组第一个元素去重
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum > 0)
                right--;
            else if (sum < 0)
                left++;
            else {
                res.push_back({nums[i], nums[left], nums[right]});
                // 三元组第二个元素去重
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                // 三元组第三个元素去重
                while (left < right && nums[left] == nums[left + 1])
                    left++;

                // 找到符合条件的三元组后两个指针同时收缩
                left++;
                right--;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    // vector<vector<int>> res = threeSum(nums);
    vector<vector<int>> res = threeSum2(nums);
    for (vector<int> vec : res) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
