/*
    Topic link: https://leetcode.cn/problems/remove-linked-list-elements/
*/
#include "../utils/ListNode.h"
#include <iostream>
using namespace std;

// using dummy head node
ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy_head = new ListNode(0);
    dummy_head->next = head;

    ListNode *ptr = dummy_head;
    while (ptr->next != nullptr) {
        if (ptr->next->val == val) {
            ListNode *temp = ptr->next;
            ptr->next = ptr->next->next; // 注意先调整指针指向
            delete temp;                 // 再释放结点
        } else {
            ptr = ptr->next;
        }
    }

    head = dummy_head->next;
    delete dummy_head;

    return head;
}

int main(int argc, char *argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(6);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(5);
    ListNode *node7 = new ListNode(6, nullptr);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    ListNode *dummy_head = new ListNode(0);
    dummy_head->next = removeElements(node1, 6);
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
    delete ptr; // delete v_head;
    return 0;
}
