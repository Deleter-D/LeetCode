/*
    Topic link: https://leetcode.cn/problems/binary-search/
*/
#include <iostream>
#include <vector>
using namespace std;

//  search range: [begin, end]
int search(vector<int> &nums, int target) {
    int begin = 0, end = nums.size() - 1;
    while (begin <= end) {
        int middle = (end - begin) / 2 + begin;
        if (target == nums[middle])
            return middle;
        else if (target < nums[middle])
            end = middle - 1;
        else
            begin = middle + 1;
    }
    return -1;
}

// search range: [begin, end)
int search2(vector<int> &nums, int target) {
    int begin = 0, end = nums.size();
    while (begin < end) {
        int middle = (end - begin) / 2 + begin;
        if (target == nums[middle])
            return middle;
        else if (target < nums[middle])
            end = middle;
        else
            begin = middle + 1;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    cout << search(nums, 2) << endl;
    cout << search2(nums, 2) << endl;
    return 0;
}
