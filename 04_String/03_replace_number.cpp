/*
    Topic link: https://kamacoder.com/problempage.php?pid=1064
*/
#include <iostream>
#include <string>
using namespace std;

string replaceNumber(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            res += s[i];
        } else {
            res += "number";
        }
    }

    return res;
}

string replaceNumber2(string s) {
    int count = 0;
    // 统计数字的个数
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            count++;
    }
    // 扩充之前将原字符串的长度记录下来
    int left = s.size() - 1;
    // 扩充原字符串
    s.resize(s.size() + 5 * count);

    int right = s.size() - 1;
    while (left >= 0 && right >= 0) {
        if (s[left] >= '0' && s[left] <= '9') {
            s[right] = 'r';
            s[right - 1] = 'e';
            s[right - 2] = 'b';
            s[right - 3] = 'm';
            s[right - 4] = 'u';
            s[right - 5] = 'n';
            right -= 6;
        } else {
            s[right] = s[left];
            right--;
        }
        left--;
    }

    return s;
}

int main(int argc, char *argv[]) {
    string s("a1b2c3");
    string res = replaceNumber(s);
    cout << res << endl;
    return 0;
}
