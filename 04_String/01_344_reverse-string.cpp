/*
    Topic link: https://leetcode.cn/problems/reverse-string/
*/
#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void reverseString2(vector<char> &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        // 构造 a ^ b 的结果，并放在 a 中
        s[left] ^= s[right];
        // 将 a ^ b 这一结果再 ^ b ，存入b中，此时 b = a, a = a ^ b
        s[right] ^= s[left];
        // a ^ b 的结果再 ^ a ，存入 a 中，此时 b = a, a = b 完成交换
        s[left] ^= s[right];
        left++;
        right--;
    }
}

int main(int argc, char *argv[]) {
    vector<char> s{'h', 'e', 'l', 'l', 'o'};
    // reverseString(s);
    reverseString2(s);
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
