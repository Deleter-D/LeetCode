#pragma once

#include <vector>

class NaryTreeNode {
  public:
    int val;
    std::vector<NaryTreeNode *> children;

    NaryTreeNode() {}

    NaryTreeNode(int _val) { val = _val; }

    NaryTreeNode(int _val, std::vector<NaryTreeNode *> _children) {
        val = _val;
        children = _children;
    }
};
