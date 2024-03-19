/*
    Topic link:
   https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        // 栈空或栈顶元素与当前字符不相同则入栈
        if (st.empty() || st.top() != c)
            st.push(c);
        else
            st.pop();
    }

    // 栈中剩余的元素即为逆序的结果字符串
    string res("");
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char *argv[]) {
    string s("abbaca");
    cout << removeDuplicates(s) << endl;
    return 0;
}
