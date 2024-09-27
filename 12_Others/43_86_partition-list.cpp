/*
    Topic link: https://leetcode.cn/problems/partition-list/
*/
#include "utils/ListNode.h"
#include <iostream>

ListNode *partition(ListNode *head, int x) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *smallDummy = new ListNode(-1);
    ListNode *largeDummy = new ListNode(-1);
    ListNode *small = smallDummy;
    ListNode *large = largeDummy;
    ListNode *node = head;

    while (node != nullptr) {
        ListNode *next = node->next;
        if (node->val < x) {
            small->next = node;
            small = small->next;
        } else {
            large->next = node;
            large = large->next;
        }
        node->next = nullptr;
        node = next;
    }

    small->next = largeDummy->next;

    return smallDummy->next;
}

int main(int argc, char const *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;
    ListNode *res = partition(head, x);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
