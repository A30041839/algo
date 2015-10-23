#include "leetcode.h"

using namespace std;

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root or !p) {
            return nullptr;
        }
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }
        TreeNode* ptr = root;
        stack<TreeNode*> stk;
        while (ptr != p) {
            stk.push(ptr);
            ptr = p->val < ptr->val ? ptr->left : ptr->right;
        }
        while (!stk.empty() and stk.top()->left != ptr) {
            ptr = stk.top();
            stk.pop();
        }
        return stk.empty() ? nullptr : stk.top();
    }
};
