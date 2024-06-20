/*
    Topic link: https://leetcode.cn/problems/swap-nodes-in-pairs/
*/
#include "utils/ListNode.h"
#include <iostream>
using namespace std;

ListNode *swapPairs(ListNode *head) {
    ListNode *dummy_head = new ListNode(0, head);

    ListNode *ptr = dummy_head;
    while (ptr->next != nullptr && ptr->next->next != nullptr) {
        ListNode *temp = ptr->next;              // 待交换对的左结点
        ListNode *temp1 = ptr->next->next->next; // 下一个待交换对的左结点

        ptr->next = ptr->next->next; // 上一对的右结点指向当前待交换对的右结点
        ptr->next->next = temp; // 当前待交换对的右结点指向左结点
        // 当前待交换对的左结点（即交换后的右结点）指向下一对的左结点
        ptr->next->next->next = temp1;

        ptr = ptr->next->next; // 向后移动两个结点
    }
    return dummy_head->next;
}

int main(int argc, char *argv[]) {

    int node_count = 4;

    ListNode *nodes[node_count];
    for (int i = 0; i < node_count; i++) {
        nodes[i] = new ListNode(i + 1);
    }

    for (int i = 0; i < node_count - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    ListNode *res = swapPairs(nodes[0]);

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
