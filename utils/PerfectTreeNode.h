#pragma once

class PerfectTreeNode {
  public:
    int val;
    PerfectTreeNode *left;
    PerfectTreeNode *right;
    PerfectTreeNode *next;

    PerfectTreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    PerfectTreeNode(int _val)
        : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    PerfectTreeNode(int _val, PerfectTreeNode *_left, PerfectTreeNode *_right,
                    PerfectTreeNode *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
