/*
    Topic link: https://kamacoder.com/problempage.php?pid=1065
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void rightRotate(int k, string &s) {
    int size = s.size();
    // 记录待右旋部分
    string temp(s.cbegin() + s.size() - k, s.cend());
    s = temp + s;
    s.resize(size);
}

void rightRotate2(int k, string &s) {
    // 整体反转
    reverse(s.begin(), s.end());
    // 两部分分别反转
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
}

int main(int argc, char *argv[]) {
    int k = 2;
    string s = "abcdefg";
    rightRotate(k, s);
    cout << s << endl;
    return 0;
}
