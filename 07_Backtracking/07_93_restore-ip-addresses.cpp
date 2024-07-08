/*
    Topic link: https://leetcode.cn/problems/restore-ip-addresses/
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(const string &s, int start, int end) {
    if (start > end)
        return false;

    if (s[start] == '0' && start != end) // 0开头的数字不合法
        return false;

    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] > '9' || s[i] < '0') // 非法字符
            return false;

        num = num * 10 + (s[i] - '0');
        if (num > 255) // 数值大于255不合法
            return false;
    }

    return true;
}

void backtracking(vector<string> &res, string &s, int startIdx, int dotCount) {
    if (dotCount == 3) { // 点的个数为3时终止
        // 判断第四段子串是否合法
        if (isValid(s, startIdx, s.size() - 1)) {
            res.push_back(s);
        }
        return;
    }

    for (int i = startIdx; i < s.size(); i++) {
        if (isValid(s, startIdx, i)) { // 判断[startIdx, i]区间内的子串是否合法
            s.insert(s.begin() + i + 1, '.'); // 位置i之后插入一个点
            dotCount++;
            backtracking(res, s, i + 2,
                         dotCount); // 插入点之后，下一个起始位置要+2
            dotCount--;             // 回溯
            s.erase(s.begin() + i + 1); // 回溯，删除插入的点
        } else {
            break; // 不合法直接结束循环
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    // 剪枝
    if (s.size() < 4 || s.size() > 12)
        return res;
    backtracking(res, s, 0, 0);

    return res;
}

int main(int argc, char *argv[]) {
    string s = "25525511135";
    vector<string> res = restoreIpAddresses(s);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}
