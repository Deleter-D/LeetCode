/*
    Topic link:
   https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<char, vector<char>> mapping = {
    {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

vector<string> res;
string str;
void backtracing(string digits, int idx) {
    if (idx == digits.size()) {
        res.push_back(str);
        return;
    }

    vector<char> letters = mapping[digits[idx]];
    for (int i = 0; i < letters.size(); i++) {
        str.push_back(letters[i]);
        backtracing(digits, idx + 1);
        str.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits == "")
        return res;
    backtracing(digits, 0);
    return res;
}

int main(int argc, char *argv[]) {
    string digits = "23";

    vector<string> res = letterCombinations(digits);

    for (auto s : res)
        cout << s << endl;
    return 0;
}
