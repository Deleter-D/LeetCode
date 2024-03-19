/*
    Topic link: https://leetcode.cn/problems/sliding-window-maximum/
*/
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class MonotonicQueue {
  public:
    void pop(int value) {
        // 窗口移除元素等于队列出口元素
        if (!que.empty() && value == que.front()) {
            que.pop_front(); // 弹出出口元素
        }
    }

    void push(int value) {
        // push元素大于队列入口元素
        while (!que.empty() && value > que.back()) {
            que.pop_back(); // 弹出入口元素
        }
        // 最后向入口push元素
        que.push_back(value);
    }

    int front() { return que.front(); }

  private:
    deque<int> que;
};

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    MonotonicQueue que;
    vector<int> res;
    // 将前k个元素放入队列
    for (int i = 0; i < k; i++) {
        que.push(nums[i]);
    }
    // 记录当前窗口最大值
    res.push_back(que.front());
    for (int i = k; i < nums.size(); i++) {
        que.pop(nums[i - k]);       // 窗口移除最前面的元素
        que.push(nums[i]);          // 窗口加入最后面的元素
        res.push_back(que.front()); // 记录当前窗口最大值
    }

    return res;
}

int main(int argc, char *argv[]) {
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
