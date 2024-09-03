/*
    Topic link: https://leetcode.cn/problems/valid-palindrome/
*/
#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
        if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') &&
            (s[i] < '0' || s[i] > '9')) {
            s[i] = ' ';
        }
    }

    for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
        while (s[left] == ' ' && left < right) {
            left++;
        }
        while (s[right] == ' ' && left < right) {
            right--;
        }
        if (s[left] != s[right]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::string s("A man, a plan, a canal: Panama");

    bool res = isPalindrome(s);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
