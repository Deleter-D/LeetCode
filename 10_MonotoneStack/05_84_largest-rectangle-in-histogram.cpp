/*
    Topic link: https://leetcode.cn/problems/largest-rectangle-in-histogram/
*/
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

int largestRectangleArea(std::vector<int> &heights) {
    std::stack<int> st;
    int area = 0;

    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    st.push(0);
    for (int i = 1; i < heights.size(); i++) {
        if (heights[i] > heights[st.top()]) {
            st.push(i);
        } else if (heights[i] == heights[st.top()]) {
            st.pop();
            st.push(i);
        } else {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    area = std::max(h * w, area);
                }
            }
            st.push(i);
        }
    }

    return area;
}

int main(int argc, char *argv[]) {
    std::vector<int> heights{2, 1, 5, 6, 2, 3};

    int res = largestRectangleArea(heights);

    std::cout << res << std::endl;
    return 0;
}
