/*
    Topic link: https://leetcode.cn/problems/trapping-rain-water/
*/
#include <iostream>
#include <stack>
#include <vector>

int trap(std::vector<int> &height) {
    std::stack<int> st;
    int volumn = 0;

    st.push(0);
    for (int i = 1; i < height.size(); i++) {
        if (height[i] < height[st.top()]) {
            st.push(i);
        } else if (height[i] == height[st.top()]) {
            st.pop();
            st.push(i);
        } else {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int h = std::min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    volumn += h * w;
                }
            }
            st.push(i);
        }
    }

    return volumn;
}

int main(int argc, char *argv[]) {
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int res = trap(height);

    std::cout << res << std::endl;
    return 0;
}
