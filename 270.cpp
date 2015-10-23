#include "leetcode.h"

using namespace std;

#define EPS 1e-5
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* ptr = root;
        int res = root->val;
        while (ptr) {
            if (fabs(ptr->val - target) < fabs(res - target)) {
                res = ptr->val;
            }
            if (ptr->val < target) {
                ptr = ptr->right;
            }else {
                ptr = ptr->left;
            }
        }
        return res;
    }
};
