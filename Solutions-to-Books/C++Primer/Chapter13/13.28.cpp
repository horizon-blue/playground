// Exercise 13.28
// Given the following classes, implement a default constructor and the
// necessary copy-control members
// Xiaoyan Wang 12/28/2016

// (a)
// class TreeNode {
// private:
//     std::string value;
//     int count;
//     TreeNode *left;
//     TreeNode *right;
// };

// (b)
// class BinStrTree {
// private:
//     TreeNode *root;
// };
#include <queue>
#include <string>

class TreeNode {
public:
    TreeNode(const std::string &s = std::string(), TreeNode &l, TreeNode &r)
        : value(s), count(0), left(&l), right(&r) {}

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
    BinStrTree() : root(nullptr);
    BinStrTree(TreeNode &t) : root(&t) {}

private:
    TreeNode *root;
};