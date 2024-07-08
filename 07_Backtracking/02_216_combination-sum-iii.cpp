/*
    Topic link: https://leetcode.cn/problems/combination-sum-iii/
*/
#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<int> &path, int sum, vector<vector<int>> &res, int k,
                  int n, int startIdx) {
    if (sum > n) { // 剪枝
        return;
    }
    if (path.size() == k) { // 终止条件
        if (sum == n)
            res.push_back(path);
        return;
    }

    for (int i = startIdx; i <= 9; i++) {
        path.push_back(i);
        sum += i;
        backtracking(path, sum, res, k, n, i + 1);
        sum -= i;        // 回溯
        path.pop_back(); // 回溯
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    backtracking(path, 0, res, k, n, 1);

    return res;
}

int main(int argc, char *argv[]) {
    int k = 3;
    int n = 7;
    vector<vector<int>> res = combinationSum3(k, n);
    for (vector<int> vec : res) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
