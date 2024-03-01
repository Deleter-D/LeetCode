/*
    Topic link: https://leetcode.cn/problems/design-linked-list/
*/
#include <iostream>
#include <ostream>
using namespace std;

class MyLinkedList {
  public:
    // 定义链表结点
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList() {
        _dummy_head = new LinkedNode(0); // 虚头结点
        _size = 0;                       // 记录链表长度
    }

    int get(int index) {
        // 若index不合法则返回-1
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        // index从0开始，所以第0个结点是真正的头结点，不是虚头结点
        LinkedNode *ptr = _dummy_head->next;
        // for (int i = 0; i < index; i++) {
        //     ptr = ptr->next;
        // }
        while (index--) {
            ptr = ptr->next;
        }

        return ptr->val;
    }

    void addAtHead(int val) {
        LinkedNode *new_node = new LinkedNode(val);
        new_node->next = _dummy_head->next;
        _dummy_head->next = new_node;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode *new_node = new LinkedNode(val);
        LinkedNode *ptr = _dummy_head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size)
            return;
        if (index < 0)
            index = 0;

        LinkedNode *new_node = new LinkedNode(val);
        LinkedNode *ptr = _dummy_head;
        // for (int i = 0; i < index; i++) {
        //     ptr = ptr->next;
        // }
        while (index--) {
            ptr = ptr->next;
        }

        new_node->next = ptr->next;
        ptr->next = new_node;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0)
            return;

        // 这里与get中不同，因为本质上是寻找目标结点的前一个结点
        LinkedNode *ptr = _dummy_head;
        // for (int i = 0; i < index; i++) {
        //     ptr = ptr->next;
        // }
        while (index--) {
            ptr = ptr->next;
        }

        LinkedNode *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
        // 释放temp后需要赋值为nullptr，否则temp就变成了野指针，比较危险
        temp = nullptr;
        _size--;
    }

    void printLinkedList() {
        LinkedNode *ptr = _dummy_head;
        while (ptr->next != nullptr) {
            cout << ptr->next->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

  private:
    // 此处一定要使用有符号数，因为存在虚头结点，判断链表尺寸时可能出现-1的情况
    int _size;
    LinkedNode *_dummy_head;
};

int main(int argc, char *argv[]) {
    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2); // 链表变为 1->2->3
    linkedList.printLinkedList();

    cout << linkedList.get(1) << endl; // 返回 2

    linkedList.deleteAtIndex(1); // 现在，链表变为 1->3
    linkedList.printLinkedList();

    cout << linkedList.get(1) << endl; // 返回 3
    cout << linkedList.get(3) << endl;

    linkedList.deleteAtIndex(3);
    linkedList.deleteAtIndex(0);

    cout << linkedList.get(0) << endl;

    linkedList.deleteAtIndex(0);

    cout << linkedList.get(0) << endl;

    return 0;
}
