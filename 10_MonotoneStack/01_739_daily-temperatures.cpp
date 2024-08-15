/*
        Topic link: https://leetcode.cn/problems/daily-temperatures/
*/
#include <algorithm>
#include <ctime>
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    std::stack<int> st;
    std::vector<int> res(temperatures.size(), 0);

    st.push(0);

    for (int i = 1; i < temperatures.size(); i++) {
        if (temperatures[i] < temperatures[st.top()]) {
            st.push(i);
        } else if (temperatures[i] == temperatures[st.top()]) {
            st.push(i);
        } else {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};

    auto res = dailyTemperatures(temperatures);

    std::for_each(res.begin(), res.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
    return 0;
}
