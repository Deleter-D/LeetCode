/*
    Topic link:
   https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
*/
#include "utils/ListNode.h"
#include <iostream>

ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *dummy = new ListNode(-1, head);
    ListNode *prev = dummy;
    ListNode *cur = prev->next;

    while (cur != nullptr && cur->next != nullptr) {
        ListNode *succ = cur->next;
        if (cur->val == succ->val) {
            while (cur->val == succ->val) {
                cur = cur->next;
                if (cur->next == nullptr) {
                    succ = nullptr;
                    break;
                }
                succ = cur->next;
            }
            prev->next = succ;
            cur = succ;
        } else {
            prev = prev->next;
            cur = cur->next;
        }
    }

    return dummy->next;
}

int main(int argc, char const *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);

    ListNode *res = deleteDuplicates(head);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
