/*
    Topic link: https://leetcode.cn/problems/4sum-ii/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                 vector<int> &nums4) {
    unordered_map<int, int> record; // 记录前两个数组出现过的和
    for (int num1 : nums1) {
        for (int num2 : nums2) {
            record[num1 + num2]++;
        }
    }
    int count = 0;
    for (int num3 : nums3) {
        for (int num4 : nums4) {
            // 判断0与后两个数组出现的和的差值是否出现过
            if (record.find(0 - (num3 + num4)) != record.cend()) {
                count += record[0 - (num3 + num4)];
            }
        }
    }
    return count;
}

int main(int argc, char *argv[]) { return 0; }
