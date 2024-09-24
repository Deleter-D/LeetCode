/*
    Topic link: https://leetcode.cn/problems/reverse-linked-list-ii/
*/
#include "utils/ListNode.h"
#include <iostream>

ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head->next == nullptr)
        return head;

    ListNode *dummy = new ListNode(-1, head);
    ListNode *prev = dummy;
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    ListNode *cur = prev->next;
    ListNode *succ;

    for (int i = 0; i < right - left; i++) {
        succ = cur->next;
        cur->next = succ->next;
        succ->next = prev->next;
        prev->next = succ;
    }

    return dummy->next;
}

int main(int argc, char const *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2, right = 4;

    ListNode *res = reverseBetween(head, left, right);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
