/*
    Topic link: https://leetcode.cn/problems/reverse-string-ii/
*/
#include <iostream>
#include <string>
using namespace std;

void reverse(string &s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

string reverseStr(string s, int k) {
    // for循环一次前进2k个字符
    for (int i = 0; i < s.size(); i += (2 * k)) {
        // 若剩余字符小于2k但大于k个，则反转前k个
        if (i + k <= s.size()) {
            reverse(s, i, i + k - 1);
            continue;
        }
        // 剩余字符少于k个，则将剩余字符全部反转
        reverse(s, i, s.size() - 1);
    }
    return s;
}

int main(int argc, char *argv[]) {
    string s("abcdefg");
    string res = reverseStr(s, 2);
    cout << res << endl;
    return 0;
}
