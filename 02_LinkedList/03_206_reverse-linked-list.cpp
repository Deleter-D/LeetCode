/*
    Topic link: https://leetcode.cn/problems/reverse-linked-list/
*/
#include "utils/ListNode.h"
#include <iostream>
using namespace std;

ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;     // 记录当前结点
    ListNode *prev = nullptr; // 记录原链表的前一个结点

    ListNode *temp;
    while (cur != nullptr) {
        temp = cur->next; // 记录原链表中当前结点的下一个结点
        cur->next = prev; // 将当前结点的next指针反转，指向前一个结点
        prev = cur; // prev指针向原链表方向前进一步
        cur = temp; // cur指针也向原链表方向前进一步
    }
    return prev; // 当cur指向了nullptr，prev指向的就是原链表的最后一个结点
}

ListNode *reverse(ListNode *prev, ListNode *cur) {
    if (cur == nullptr) // 递归终止条件为cur指向了nullptr
        return prev;

    ListNode *temp = cur->next;
    cur->next = prev;
    // 这里的递归等价于prev = cur; cur = temp;这两步
    return reverse(cur, temp);
}

ListNode *reverseList2(ListNode *head) { return reverse(nullptr, head); }

int main(int argc, char *argv[]) {
    int node_count = 5;

    ListNode *nodes[node_count];
    for (int i = 0; i < node_count; i++) {
        nodes[i] = new ListNode(i + 1);
    }

    for (int i = 0; i < node_count - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // ListNode *res = reverseList(nodes[0]);
    ListNode *res = reverseList2(nodes[0]);

    ListNode *dummy_head = new ListNode(0);
    dummy_head->next = res;
    ListNode *ptr = dummy_head;
    while (ptr->next != nullptr) {
        cout << ptr->next->val << " ";
        ptr = ptr->next;
    }
    cout << endl;

    ptr = dummy_head;
    while (ptr->next != nullptr) {
        ListNode *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    ptr = nullptr;
    delete dummy_head;
    return 0;
}
