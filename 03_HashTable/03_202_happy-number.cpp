/*
    Topic link: https://leetcode.cn/problems/happy-number/
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> getNums(int n) { // 获取数字的每一位
    vector<int> nums;
    while (n != 0) {
        nums.push_back(n % 10);
        n /= 10;
    }
    return nums;
}

bool isHappy(int n) {
    unordered_set<int> sums;
    while (true) {
        vector<int> nums = getNums(n);
        int sum = 0;
        for (int num : nums) {
            sum += num * num; // 计算每一位数的平方和
        }
        if (sum == 1)
            return true;

        if (sums.find(sum) != sums.cend())
            return false; // 若和之前出现过，则为非快乐数
        else {
            sums.insert(sum);
            n = sum;
        }
    }
}

int main(int argc, char *argv[]) {
    int n = 2;
    cout << isHappy(n) << endl;
    return 0;
}
