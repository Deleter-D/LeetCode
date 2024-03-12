/*
    Topic link:
   https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getNext(string s) {
    // i指向前缀末尾，j指向后缀末尾
    vector<int> next(s.size());
    int j = -1;
    next[0] = j; // 初始化为-1
    // j初始化为-1,所以i从1开始，与j+1比较
    for (int i = 1; i < s.size(); i++) {
        // 前后缀不同的情况
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j]; // 向前回退
        }
        if (s[i] == s[j + 1]) { // 前后缀相同
            j++;
        }
        next[i] = j; // 记录最长公共前后缀长度
    }
    return next;
}

int strStr(string haystack, string needle) {
    if (needle.size() == 0)
        return 0;

    vector<int> next = getNext(needle);
    int j = -1; // 因为next数组记录的起始位置为-1
    // 这里i从0开始
    for (int i = 0; i < haystack.size(); i++) {
        // 字符不匹配的情况
        while (j >= 0 && haystack[i] != needle[j + 1]) {
            j = next[j]; // 寻找之前匹配的位置
        }
        // 字符匹配则i，j同时向后移动
        if (haystack[i] == needle[j + 1]) {
            j++;
        }
        // 字符串完全匹配
        if (j == (needle.size() - 1)) {
            return (i - needle.size() + 1);
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    string haystack("sadbutsad");
    string needle("sad");
    cout << strStr(haystack, needle) << endl;
    return 0;
}
