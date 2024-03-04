/*
    Topic link: https://leetcode.cn/problems/intersection-of-two-arrays/
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> res; // 为了去重，结果暂时存放在set中
    // 将nums1的数据存入一个set去重
    unordered_set<int> nums_set(nums1.cbegin(), nums1.cend());
    for (int num : nums2) {
        // 判断nums2中的数有没有在nums1中出现过
        if (nums_set.find(num) != nums_set.cend()) {
            res.insert(num);
        }
    }

    return vector<int>(res.cbegin(), res.cend());
}

int main(int argc, char *argv[]) {
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    vector<int> res = intersection(nums1, nums2);

    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
