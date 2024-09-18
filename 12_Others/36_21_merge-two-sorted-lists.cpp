/*
    Topic link: https://leetcode.cn/problems/merge-two-sorted-lists/
*/
#include "utils/ListNode.h"
#include <iostream>

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;

    if (list1 == nullptr) {
        if (list2 == nullptr) {
            return dummy->next;
        } else {
            return list2;
        }
    } else {
        if (list2 == nullptr) {
            return list1;
        }
    }

    if (list1->val < list2->val) {
        dummy->next = list1;
        list1 = list1->next;
        prev = dummy->next;
    }

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            prev->next = list1;
            list1 = list1->next;
            prev = prev->next;
        } else {
            prev->next = list2;
            list2 = list2->next;
            prev = prev->next;
        }
    }

    if (list1 != nullptr) {
        prev->next = list1;
    }
    if (list2 != nullptr) {
        prev->next = list2;
    }

    return dummy->next;
}

int main(int argc, char const *argv[]) {
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *res = mergeTwoLists(list1, list2);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
