/*
    Topic link: https://leetcode.cn/problems/two-sum/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> record; // 记录出现过的数字和下标
    for (int i = 0; i < nums.size(); i++) {
        // 寻找目标数与当前数的差值是否出现过
        auto iter = record.find(target - nums[i]);
        if (iter != record.cend()) {
            return {i, iter->second};
        }
        record[nums[i]] = i; // 没有出现则将当前数记录下来
    }
    return {};
}

int main(int argc, char *argv[]) {
    vector<int> nums{3, 2, 4};
    int target = 6;

    vector<int> res = twoSum(nums, target);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
