/*
    Topic link:
   https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

std::string reverseParentheses(std::string s) {
    std::stack<std::string> st;

    std::string str("");
    for (char &c : s) {
        if (c == '(') {
            st.push(str);
            str = "";
        } else if (c == ')') {
            std::reverse(str.begin(), str.end());
            str = st.top() + str;
            st.pop();
        } else {
            str.push_back(c);
        }
    }

    return str;
}

int main(int argc, char const *argv[]) {
    std::string s("(ed(et(oc))el)");

    std::string res = reverseParentheses(s);

    std::cout << res << std::endl;
    return 0;
}
