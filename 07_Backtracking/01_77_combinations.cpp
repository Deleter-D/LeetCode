/*
    Topic link: https://leetcode.cn/problems/combinations/
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtracking(int n, int k, int startIdx) {
    // path的大小与k相同时表明已经取完了
    if (path.size() == k) {
        res.push_back(path);
        return;
    }
    for (int i = startIdx; i <= n; i++) {
        path.push_back(i);         // 处理当前结点
        backtracking(n, k, i + 1); // 递归
        path.pop_back();           // 回溯，撤销选择的结点
    }
}

vector<vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return res;
}

int main(int argc, char *argv[]) {
    int n = 4;
    int k = 2;

    vector<vector<int>> result = combine(n, k);
    for (vector<int> vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
