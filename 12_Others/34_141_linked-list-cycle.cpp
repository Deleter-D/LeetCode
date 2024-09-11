/*
    Topic link: https://leetcode.cn/problems/linked-list-cycle/
*/
#include "utils/ListNode.h"
#include <iostream>

bool hasCycle(ListNode *head) {
    if (head == nullptr)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    bool res = hasCycle(head);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
