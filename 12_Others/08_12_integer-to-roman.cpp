/*
    Topic link: https://leetcode.cn/problems/integer-to-roman/
*/
#include <iostream>
#include <string>

std::string intToRoman(int num) {
    std::string res;
    int tmp;

    tmp = num / 1000;
    for (int i = 0; i < tmp; i++)
        res.push_back('M');
    num -= tmp * 1000;

    if (num >= 900) {
        res.push_back('C');
        res.push_back('M');
        num -= 900;
    }

    if (num >= 500) {
        res.push_back('D');
        num -= 500;
    }

    if (num >= 400) {
        res.push_back('C');
        res.push_back('D');
        num -= 400;
    }

    tmp = num / 100;
    for (int i = 0; i < tmp; i++)
        res.push_back('C');
    num -= tmp * 100;

    if (num >= 90) {
        res.push_back('X');
        res.push_back('C');
        num -= 90;
    }

    if (num >= 50) {
        res.push_back('L');
        num -= 50;
    }

    if (num >= 40) {
        res.push_back('X');
        res.push_back('L');
        num -= 40;
    }

    tmp = num / 10;
    for (int i = 0; i < tmp; i++)
        res.push_back('X');
    num -= tmp * 10;

    if (num >= 9) {
        res.push_back('I');
        res.push_back('X');
        num -= 9;
    }

    if (num >= 5) {
        res.push_back('V');
        num -= 5;
    }

    if (num >= 4) {
        res.push_back('I');
        res.push_back('V');
        num -= 4;
    }

    for (int i = 0; i < num; i++) {
        res.push_back('I');
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string res = intToRoman(3749);

    std::cout << res << std::endl;
    return 0;
}
