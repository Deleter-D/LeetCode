/*
    Topic link: https://leetcode.cn/problems/copy-list-with-random-pointer/
*/
#include "utils/RandomListNode.h"
#include <iostream>
#include <unordered_map>

Node *copyRandomList(Node *head) {
    Node *res = new Node(-1);

    Node *originNode = head;
    Node *newNode = res;

    std::unordered_map<Node *, Node *> umap;

    while (originNode != nullptr) {
        newNode->next = new Node(originNode->val);
        umap.insert({originNode, newNode->next});
        newNode = newNode->next;
        originNode = originNode->next;
    }

    originNode = head;
    newNode = res->next;
    while (newNode != nullptr) {
        newNode->random = umap[originNode->random];
        newNode = newNode->next;
        originNode = originNode->next;
    }

    return res->next;
}

int main(int argc, char const *argv[]) {
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;                               // 7
    head->next->next->random = head->next->next->next->next; // 1
    head->next->next->next->random = head->next->next;       // 11
    head->next->next->next->next->random = head;             // 7

    Node *res = copyRandomList(head);

    while (res != nullptr) {
        std::cout << res->val << " "
                  << (res->random == nullptr ? "null"
                                             : std::to_string(res->random->val))
                  << std::endl;
        res = res->next;
    }

    return 0;
}
