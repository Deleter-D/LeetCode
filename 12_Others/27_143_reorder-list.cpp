/*
    Topic link: https://leetcode.cn/problems/reorder-list/
*/
#include "utils/ListNode.h"
#include <iostream>

ListNode *midNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *reverse(ListNode *node) {
    ListNode *cur = node;
    ListNode *prev = nullptr;

    ListNode *tmp;
    while (cur != nullptr) {
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    return prev;
}

void reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    ListNode *mid = midNode(head);

    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = nullptr;

    right = reverse(right);

    ListNode *left_tmp;
    ListNode *right_tmp;

    while (left != nullptr && right != nullptr) {
        left_tmp = left->next;
        right_tmp = right->next;

        left->next = right;
        left = left_tmp;

        right->next = left;
        right = right_tmp;
    }
}

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    reorderList(head);

    ListNode *res = head;
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            std::cout << res->val;
        } else {

            std::cout << " -> " << res->val;
        }
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
