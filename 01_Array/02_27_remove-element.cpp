/*
    Topic link: https://leetcode.cn/problems/remove-element/
*/
#include <iostream>
#include <vector>
using namespace std;

// violent solution
int removeElement(vector<int> &nums, int val) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        if (nums[i] == val) {
            for (int j = i + 1; j < size; j++)
                nums[j - 1] = nums[j];
            --i;
            --size;
        }
    }
    return size;
}

// double pointer solution
int removeElement2(vector<int> &nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        if (nums[fastIndex] != val)
            nums[slowIndex++] = nums[fastIndex];
    return slowIndex;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{1, 2, 2, 3, 3, 0, 4, 2};
    // int len = removeElement(nums, 2);
    int len = removeElement2(nums, 2);
    cout << len << endl;
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
