/*
    Topic link: https://leetcode.cn/problems/combination-sum-iii/
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;
int sum = 0;

void backtracing(int k, int n, int startIdx) {
    if (sum > n)
        return;

    if (path.size() == k) {
        if (sum == n)
            res.push_back(path);
        return;
    }

    for (int i = startIdx; i <= 9; i++) {
        path.push_back(i);
        sum += i;
        backtracing(k, n, i + 1);
        sum -= i;
        path.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    backtracing(k, n, 1);
    return res;
}

int main(int argc, char *argv[]) {
    int k = 9, n = 45;
    vector<vector<int>> res = combinationSum3(k, n);

    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
