/*
    Topic link: https://leetcode.cn/problems/top-k-frequent-elements/
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> record;
    // 统计元素频率
    for (int num : nums) {
        record[num]++;
    }

    // 定义比较器
    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    };
    // 利用自定义比较器定义优先级队列
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
        small_top_heap(cmp);
    for (pair<int, int> elem : record) {
        small_top_heap.push(elem);
        // 保持小顶堆中只有k个元素
        if (small_top_heap.size() > k) {
            small_top_heap.pop();
        }
    }

    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(small_top_heap.top().first);
        small_top_heap.pop();
    }

    return res;
}

int main(int argc, char *argv[]) {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
