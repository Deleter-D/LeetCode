/*
    Topic link: https://leetcode.cn/problems/implement-stack-using-queues/
*/
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
  public:
    MyStack() {}

    void push(int x) { queue1.push(x); }

    int pop() {
        int size = queue1.size() - 1;
        while (size--) { // 中转，但留下最后一个元素
            queue2.push(queue1.front());
            queue1.pop();
        }
        int res = queue1.front();
        queue1.pop();
        while (!queue2.empty()) { // 再转移回去
            queue1.push(queue2.front());
            queue2.pop();
        }

        return res;
    }

    int top() { return queue1.back(); }

    bool empty() { return queue1.empty(); }

  private:
    queue<int> queue1; // 数据队列
    queue<int> queue2; // 中转队列
};

int main(int argc, char *argv[]) {
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
    return 0;
}
