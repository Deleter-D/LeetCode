/*
    Topic link: https://leetcode.cn/problems/roman-to-integer/
*/
#include <iostream>
#include <string>

int romanToInt(std::string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        switch (s[i]) {
        case 'I':
            if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                res -= 1;
            } else {
                res += 1;
            }
            break;
        case 'V':
            res += 5;
            break;
        case 'X':
            if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                res -= 10;
            } else {
                res += 10;
            }
            break;
        case 'L':
            res += 50;
            break;
        case 'C':
            if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                res -= 100;
            } else {
                res += 100;
            }
            break;
        case 'D':
            res += 500;
            break;
        case 'M':
            res += 1000;
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string s("MCMXCIV");

    int res = romanToInt(s);

    std::cout << res << std::endl;
    return 0;
}
