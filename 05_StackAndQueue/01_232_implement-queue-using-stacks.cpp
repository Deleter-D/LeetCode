/*
    Topic link: https://leetcode.cn/problems/implement-queue-using-stacks/
*/
#include <iostream>
#include <ostream>
#include <stack>
using namespace std;

class MyQueue {
  public:
    MyQueue() {}

    void push(int x) { stack1.push(x); }

    int pop() {
        while (!stack1.empty()) { // 数据转移到中转栈
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();   // 获取队头数据
        stack2.pop();             // 该数据出队
        while (!stack2.empty()) { // 转移回数据栈
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

    int peek() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

    bool empty() { return stack1.empty(); }

  private:
    stack<int> stack1; // 数据栈
    stack<int> stack2; // 中转栈
};

class MyQueue2 {
  public:
    MyQueue2() {}

    void push(int x) { stack_in.push(x); }

    int pop() {
        int res;
        if (stack_out.empty()) { // 若输出栈空则搬移
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        // 否则直接pop
        res = stack_out.top();
        stack_out.pop();

        return res;
    }

    int peek() {
        int temp = this->pop(); // 借助pop
        stack_out.push(temp);   // 再将pop的元素push回输出栈
        return temp;
    }

    bool empty() { return stack_in.empty() && stack_out.empty(); }

  private:
    stack<int> stack_in;  // 输入栈
    stack<int> stack_out; // 输出栈
};

int main(int argc, char *argv[]) {
    // MyQueue *obj = new MyQueue();
    MyQueue2 *obj = new MyQueue2();
    obj->push(1);
    obj->push(2);
    cout << obj->peek() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
    return 0;
}
