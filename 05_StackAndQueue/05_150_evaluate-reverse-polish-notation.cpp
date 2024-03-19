/*
    Topic link: https://leetcode.cn/problems/evaluate-reverse-polish-notation/
*/
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int evalRPN(vector<string> &tokens) {
    stack<int> st;
    int left, right;
    for (string s : tokens) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            right = st.top();
            st.pop();
            left = st.top();
            st.pop();

            if (s == "+")
                st.push(left + right);
            if (s == "-")
                st.push(left - right);
            if (s == "*")
                st.push(left * right);
            if (s == "/")
                st.push(left / right);
        } else {
            int num;
            istringstream iss(s);
            iss >> num;
            st.push(num);
        }
    }

    return st.top();
}

int main(int argc, char *argv[]) {
    vector<string> tokens{"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens) << endl;
    return 0;
}
