/*
    Topic link: https://leetcode.cn/problems/squares-of-a-sorted-array/
*/
#include <iostream>
#include <vector>
using namespace std;

// double pointer solution
vector<int> sortedSquares(vector<int> &nums) {
    int k = nums.size() - 1;
    vector<int> res(nums.size(), 0);
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        if (nums[i] * nums[i] < nums[j] * nums[j]) {
            res[k--] = nums[j] * nums[j];
            --j;
        } else {
            res[k--] = nums[i] * nums[i];
            ++i;
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{-4, -1, 0, 3, 10};
    auto res = sortedSquares(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
