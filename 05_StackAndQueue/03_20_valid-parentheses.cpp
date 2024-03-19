/*
    Tpoic link: https://leetcode.cn/problems/valid-parentheses/
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.size() % 2 != 0)
        return false;
    stack<char> st;
    for (char c : s) {
        // 碰到左括号，则push对应类型的右括号
        if (c == '(')
            st.push(')');
        else if (c == '[')
            st.push(']');
        else if (c == '{')
            st.push('}');
        // 若栈空了或栈顶元素与当前括号不相同，则括号不匹配
        else if (st.empty() || st.top() != c)
            return false;
        // 若栈顶元素与当前括号相同，则出栈
        else
            st.pop();
    }

    return st.empty();
}

int main(int argc, char *argv[]) {
    string s("()[]{}");
    cout << isValid(s) << endl;
    return 0;
}
