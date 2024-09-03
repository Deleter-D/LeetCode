/*
    Topic link: https://leetcode.cn/problems/length-of-last-word/
*/
#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    int tail_blank = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            tail_blank++;
        } else {
            break;
        }
    }

    for (int i = s.size() - 1 - tail_blank; i >= 0; i--) {
        if (s[i] == ' ')
            return s.size() - i - tail_blank - 1;
    }

    return s.size() - tail_blank;
}

int main(int argc, char *argv[]) {
    std::string s("   fly me   to   the moon  ");

    int res = lengthOfLastWord(s);

    std::cout << res << std::endl;
    return 0;
}
