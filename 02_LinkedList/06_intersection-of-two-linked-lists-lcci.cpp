/*
    Topic link:
   https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
*/
#include "utils/ListNode.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *dummy_headA = new ListNode(0,headA);
    ListNode *dummy_headB = new ListNode(0,headB);
    
    int size_A = 0,size_B =0;
    ListNode *ptrA = dummy_headA;
    ListNode *ptrB = dummy_headB;
    while(ptrA->next != nullptr){ // 统计链表A的长度
        ptrA = ptrA->next;
        size_A++;
    }
    while(ptrB->next!=nullptr){ // 统计链表B的长度
        ptrB = ptrB->next;
        size_B++;
    }

    ptrA = dummy_headA;
    ptrB = dummy_headB;
    int diff = abs(size_A -size_B);
    // 令较长的链表先走长度差，使得ptrA和ptrB对于两个链表的末尾对齐
    if(size_A > size_B){
        for(int i=0;i<diff;i++){
            ptrA = ptrA ->next;
        }
    }else {
        for(int i=0;i<diff;i++){
            ptrB = ptrB->next;
        }   
    }

    // 然后共同前进，直到指向的结点相同
    while(ptrA != ptrB){
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    
    // 若到末尾都不相同，此时ptrA指向nullptr，符合要求
    return ptrA;
}

int main(int argc, char *argv[]) {
    ListNode *listA_nodes[2];
    vector<int> listA_val{4, 1};
    for (int i = 0; i < 2; i++) {
        listA_nodes[i] = new ListNode(listA_val[i]);
    }
    for (int i = 0; i < 1; i++) {
        listA_nodes[i]->next = listA_nodes[i + 1];
    }

    ListNode *listB_nodes[3];
    vector<int> listB_val{5, 0, 1};
    for (int i = 0; i < 3; i++) {
        listB_nodes[i] = new ListNode(listB_val[i]);
    }
    for (int i = 0; i < 2; i++) {
        listB_nodes[i]->next = listB_nodes[i + 1];
    }

    ListNode *intersect_nodes[3];
    vector<int> intersect_val{8, 4, 5};
    for (int i = 0; i < 3; i++) {
        intersect_nodes[i] = new ListNode(intersect_val[i]);
    }
    for (int i = 0; i < 2; i++) {
        intersect_nodes[i]->next = intersect_nodes[i + 1];
    }

    listA_nodes[1]->next = intersect_nodes[0];
    listB_nodes[2]->next = intersect_nodes[0];

    ListNode* res =  getIntersectionNode(listA_nodes[0],listB_nodes[0]);

    ListNode *dummy_head = new ListNode(0);
    dummy_head->next = res;
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

    ListNode *dummy_head2 = new ListNode(0);
    dummy_head2->next = listB_nodes[0];
    ListNode *ptr2 = dummy_head2;
    ptr2 = dummy_head2;
    while (ptr2->next != intersect_nodes[0]) {
        ListNode *temp = ptr2->next;
        ptr2->next = ptr2->next->next;
        delete temp;
    }
    ptr2 = nullptr;
    delete dummy_head2;

    return 0;
}
