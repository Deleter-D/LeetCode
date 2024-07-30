/*
    Topic link: https://leetcode.cn/problems/monotone-increasing-digits/
*/
#include <iostream>
#include <string>

int monotoneIncreasingDigits(int n) {
    std::string s = std::to_string(n);

    int flag = s.size();
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] < s[i - 1]) {
            flag = i;
            s[i - 1]--;
        }
    }

    for (int i = flag; i < s.size(); i++) {
        s[i] = '9';
    }

    return std::stoi(s);
}

int main(int argc, char *argv[]) {
    int n = 332;

    int res = monotoneIncreasingDigits(n);

    std::cout << res << std::endl;
    return 0;
}
