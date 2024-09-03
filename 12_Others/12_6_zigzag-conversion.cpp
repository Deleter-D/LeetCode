/*
    Topic link: https://leetcode.cn/problems/zigzag-conversion/
*/
#include <iostream>
#include <string>
#include <vector>

std::string convert(std::string s, int numRows) {
    std::vector<std::string> vec(numRows, "");
    int idx = 0;
    bool goDown = true;
    while (idx < s.size()) {
        if (goDown) {
            for (int i = 0; i < numRows; i++) {
                if (idx < s.size())
                    vec[i].push_back(s[idx++]);
            }
            goDown = false;
        } else {
            for (int i = numRows - 2; i > 0; i--) {
                if (idx < s.size())
                    vec[i].push_back(s[idx++]);
            }
            goDown = true;
        }
    }

    std::string res("");
    for (std::string s : vec) {
        res += s;
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string s("PAYPALISHIRING");
    int numRows = 3;

    std::string res = convert(s, numRows);

    std::cout << res << std::endl;
    return 0;
}
