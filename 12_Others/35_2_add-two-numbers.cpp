/*
    Topic link: https://leetcode.cn/problems/add-two-numbers/
*/
#include "utils/ListNode.h"
#include <iostream>

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode();
    ListNode *node = res;

    bool isCarry = false;
    while (l1 != nullptr || l2 != nullptr) {
        int sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
        }
        if (l2 != nullptr) {
            sum += l2->val;
        }

        if (isCarry) {
            sum += 1;
        }

        if (sum > 9) {
            isCarry = true;
        } else {
            isCarry = false;
        }

        node->next = new ListNode(sum % 10);
        node = node->next;
        if (l1 != nullptr) {
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            l2 = l2->next;
        }
    }

    if (isCarry) {
        node->next = new ListNode(1);
    }

    return res->next;
}

int main(int argc, char *argv[]) {
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *res = addTwoNumbers(l1, l2);

    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
