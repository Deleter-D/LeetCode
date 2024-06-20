/*
    Topic link:
   https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
*/
#include "utils/PerfectTreeNode.h"
#include <queue>
using namespace std;

PerfectTreeNode *connect(PerfectTreeNode *root) {
    queue<PerfectTreeNode *> q;

    if (root == nullptr)
        return nullptr;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            PerfectTreeNode *node = q.front();
            q.pop();
            if (i < size - 1)
                node->next = q.front();
            else
                node->next = nullptr;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return root;
}

int main(int argc, char *argv[]) { return 0; }
