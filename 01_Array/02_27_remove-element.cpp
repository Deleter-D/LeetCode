/*
    Topic link: https://leetcode.cn/problems/remove-element/
*/
#include <iostream>
#include <vector>
using namespace std;

// violent solution
int removeElement(vector<int> &nums, int val) {
    int size = nums.size();
    for (int i = 0; i < size; ++i) { // 利用size而不是nums.size()控制循环次数
        if (nums[i] == val) {
            for (int j = i + 1; j < size; j++)
                nums[j - 1] = nums[j];
            --i; // 注意此处的下标前移
            --size; // 每次遇到满足条件的元素都要将最终返回的数组长度减1
        }
    }
    return size;
}

// double pointer solution
int removeElement2(vector<int> &nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        if (nums[fastIndex] != val) // 快指针碰到不满足条件的值
            // 将该元素覆盖到慢指针指向的待更新，并将慢指针向前移动
            nums[slowIndex++] = nums[fastIndex];
    return slowIndex; // 最终慢指针指向的就是数组尾后位置
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
