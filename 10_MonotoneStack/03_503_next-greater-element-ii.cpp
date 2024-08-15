/*
    Topic link: https://leetcode.cn/problems/next-greater-element-ii/
*/
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nextGreaterElements(std::vector<int> &nums) {
    size_t size = nums.size();
    std::stack<int> st;
    std::vector<int> res(size, -1);

    if (size == 0)
        return res;

    for (int i = 0; i < 2 * size; i++) {
        while (!st.empty() && nums[i % size] > nums[st.top()]) {
            res[st.top()] = nums[i % size];
            st.pop();
        }
        st.push(i % size);
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{1, 2, 3, 4, 3};

    auto res = nextGreaterElements(nums);

    std::for_each(res.begin(), res.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
    return 0;
}
