/*
    Topic link: https://leetcode.cn/problems/combination-sum/
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;
int sum = 0;

void backtracing(vector<int> &candidates, int target, int startIdx) {
    if (sum >= target) {
        if (sum == target)
            res.push_back(path);
        return;
    }

    for (int i = startIdx; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        sum += candidates[i];
        // next step start from i means allow pick same number
        backtracing(candidates, target, i);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    backtracing(candidates, target, 0);
    return res;
}

int main(int argc, char *argv[]) {
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> res = combinationSum(candidates, target);

    for (auto vec : res) {
        for (auto i : vec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
