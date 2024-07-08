/*
    https://leetcode.cn/problems/palindrome-partitioning/
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(const string &s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

void backtracking(vector<string> &path, vector<vector<string>> &res,
                  const string &s, int startIdx) {
    if (startIdx >= s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = startIdx; i < s.size(); i++) {
        if (isPalindrome(s, startIdx, i)) { // 是回文串则加入path
            string str = s.substr(startIdx, i - startIdx + 1);
            path.push_back(str);
        } else { // 不是回文串则跳过
            continue;
        }
        backtracking(path, res, s, i + 1); // 寻找i+1起始的子串
        path.pop_back();                   // 回溯
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    backtracking(path, res, s, 0);

    return res;
}

int main(int argc, char *argv[]) {
    string s = "aab";
    vector<vector<string>> res = partition(s);
    for (vector<string> vec : res) {
        for (string str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
