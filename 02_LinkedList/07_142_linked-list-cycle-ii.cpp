/*
    Topic link: https://leetcode.cn/problems/linked-list-cycle-ii/
*/
#include "utils/ListNode.h"
#include <iostream>
#include <vector>
using namespace std;

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) { // 保证fast走两步的合法性
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {        // 若相遇则必定有环
            ListNode *ptr1 = head; // 一个指针从头结点出发
            ListNode *ptr2 = fast; // 另一个从快慢指针相遇的结点出发
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr2; // 返回环入口
        }
    }
    return nullptr;
}

int main(int argc, char *argv[]) {
    int node_count = 4;
    vector<ListNode *> nodes;
    vector<int> vals{3, 2, 0, -4};
    for (int i = 0; i < node_count; i++) {
        nodes.push_back(new ListNode(vals[i]));
    }
    for (int i = 0; i < node_count - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[3]->next = nodes[1];

    ListNode *res = detectCycle(nodes[0]);
    cout << res->val << endl;

    nodes[3]->next = nullptr;
    ListNode *dummy_head = new ListNode(0, nodes[0]);
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
