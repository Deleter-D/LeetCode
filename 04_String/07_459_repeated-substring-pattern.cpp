/*
    Topic link: https://leetcode.cn/problems/repeated-substring-pattern/
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool repeatedSubstringPattern(string s) {
    string t = s + s;     // 拼接
    t.erase(t.begin());   // 掐头
    t.erase(t.end() - 1); // 去尾
    // find()函数未找到时会返回string::npos
    if (t.find(s) != string::npos)
        return true;

    return false;
}

vector<int> getNext(string s) {
    vector<int> next(s.size());
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < s.size(); i++) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        next[i] = j;
    }

    return next;
}

bool repeatedSubstringPattern2(string s) {
    if (s.size() == 0) {
        return false;
    }

    vector<int> next = getNext(s);
    int size = s.size();
    // 若next[size - 1] != -1说明字符串中存在最长公共前后缀
    // 如果字符串长度-最长公共前后缀长度可以被字符串长度整除
    // 即 size % (size - (next[size - 1] + 1)) == 0
    // 说明有重复的子串
    if (next[size - 1] != -1 && size % (size - (next[size - 1] + 1)) == 0) {
        return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    string s("abab");
    cout << repeatedSubstringPattern(s) << endl;
    cout << repeatedSubstringPattern2(s) << endl;
    return 0;
}
