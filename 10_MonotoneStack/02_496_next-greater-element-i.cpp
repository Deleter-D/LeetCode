/*
    Topic link: https://leetcode.cn/problems/next-greater-element-i/
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

std::vector<int> nextGreaterElement(std::vector<int> &nums1,
                                    std::vector<int> &nums2) {
    std::stack<int> st;
    std::vector<int> res(nums1.size(), -1);
    if (nums1.size() == 0)
        return res;

    std::unordered_map<int, int> um;
    for (int i = 0; i < nums1.size(); i++) {
        um[nums1[i]] = i;
    }
    st.push(0);
    for (int i = 1; i < nums2.size(); i++) {
        while (!st.empty() && nums2[i] > nums2[st.top()]) {
            if (um.count(nums2[st.top()]) > 0) {
                res[um[nums2[st.top()]]] = nums2[i];
            }
            st.pop();
        }
        st.push(i);
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums1{4, 1, 2};
    std::vector<int> nums2{1, 3, 4, 2};

    auto res = nextGreaterElement(nums1, nums2);

    std::for_each(res.begin(), res.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
    return 0;
}
