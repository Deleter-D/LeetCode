/*
    Topic link: https://leetcode.cn/problems/rotate-list/
*/
#include "utils/ListNode.h"
#include <iostream>

ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr)
        return head;
        
    ListNode *dummy = new ListNode(-1, head);

    ListNode *slow = dummy;
    ListNode *fast = dummy;

    for (int i = 0; i < k; i++) {
        fast = fast->next;
        if (fast->next == nullptr)
            fast = dummy;
    }

    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = dummy->next;
    dummy->next = slow->next;
    slow->next = nullptr;

    return dummy->next;
}

int main(int argc, char const *argv[]) {
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    int k = 4;
    ListNode *res = rotateRight(head, k);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
