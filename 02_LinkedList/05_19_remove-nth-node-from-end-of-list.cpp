/*
    Topic link: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
*/
#include "utils/ListNode.h"
#include <iostream>
using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy_head = new ListNode(0, head);

    ListNode *slow = dummy_head;
    ListNode *fast = dummy_head;
    for (int i = 0; i < n; i++) {
        fast = fast->next; // 快指针先走n步
    }
    // 快慢指针一起走，直到快指针指向最后一个结点
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy_head->next;
}

int main(int argc, char *argv[]) {

    int node_count = 5;

    ListNode *nodes[node_count];
    for (int i = 0; i < node_count; i++) {
        nodes[i] = new ListNode(i + 1);
    }

    for (int i = 0; i < node_count - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    ListNode *res = removeNthFromEnd(nodes[0], 2);

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
