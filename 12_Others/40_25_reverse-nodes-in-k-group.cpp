/*
    Topic link: https://leetcode.cn/problems/reverse-nodes-in-k-group/
*/
#include "utils/ListNode.h"
#include <iostream>
#include <utility>

std::pair<ListNode *, ListNode *> reverseBetween(ListNode *head,
                                                 ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *cur = head;
    while (prev != tail) {
        ListNode *succ = cur->next;
        cur->next = prev;
        prev = cur;
        cur = succ;
    }

    return {tail, head};
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(-1, head);
    ListNode *prev = dummy;

    while (head != nullptr) {
        ListNode *tail = prev;
        for (int i = 0; i < k; i++) {
            tail = tail->next;
            if (tail == nullptr) {
                return dummy->next;
            }
        }
        ListNode *succ = tail->next;
        auto res = reverseBetween(head, tail);
        head = res.first;
        tail = res.second;
        prev->next = head;
        tail->next = succ;
        prev = tail;
        head = tail->next;
    }

    return dummy->next;
}

int main(int argc, char const *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    ListNode *res = reverseKGroup(head, k);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
