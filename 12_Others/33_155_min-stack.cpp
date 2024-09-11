/*
    Topic link: https://leetcode.cn/problems/min-stack/
*/
#include <climits>
#include <iostream>
#include <stack>

class MinStack {
  public:
    MinStack() { this->min_st.push(INT_MAX); }

    void push(int val) {
        this->st.push(val);
        int curMinStTop = this->min_st.top();
        if (val < curMinStTop) {
            this->min_st.push(val);
        } else {
            this->min_st.push(curMinStTop);
        }
    }

    void pop() {
        this->st.pop();
        this->min_st.pop();
    }

    int top() { return this->st.top(); }

    int getMin() { return this->min_st.top(); }

  private:
    std::stack<int> st;
    std::stack<int> min_st;
};

int main(int argc, char *argv[]) {
    MinStack *obj = new MinStack();

    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    std::cout << obj->getMin() << std::endl;
    obj->pop();
    std::cout << obj->top() << std::endl;
    std::cout << obj->getMin() << std::endl;
    return 0;
}
