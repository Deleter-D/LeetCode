/*
    Topic link: https://leetcode.cn/problems/reverse-words-in-a-string/
*/
#include <iostream>
#include <string>
using namespace std;

void removeExtraSpace(string &s) {
    int slow = 0, fast = 0;
    // 去除字符串开头的空格
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ') {
        fast++;
    }
    for (; fast < s.size(); fast++) {
        // 去掉字符串中间的冗余空格，只保留一个空格
        if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ') {
            continue;
        } else {
            s[slow] = s[fast];
            slow++;
        }
    }
    if (slow - 1 > 0 && s[slow - 1] == ' ') {
        // 去除字符串末尾的空格
        s.resize(slow - 1);
    } else {
        s.resize(slow);
    }
}

void reverse(string &s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

string reverseWords(string s) {
    // 去除冗余空格
    removeExtraSpace(s);
    // 先整个反转
    reverse(s, 0, s.size() - 1);

    int start = 0;
    for (int i = 0; i <= s.size(); i++) {
        // 再逐单词反转
        if (i == s.size() || s[i] == ' ') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }

    return s;
}

int main(int argc, char *argv[]) {
    string s("the sky is blue");
    cout << reverseWords(s) << endl;
    return 0;
}
