class Solution {
public:
  int countUnivalSubtrees(TreeNode* root) {
    int res = 0;
    count(root, res);
    return res;
  }

  bool count(TreeNode* subroot, int& res) {
    if (!subroot) {
      return true;
    }
    bool l = count(subroot->left, res);
    bool r = count(subroot->right, res);
    if (l and r) {
      if ((subroot->left and subroot->left->val != subroot->val) or (subroot->right and subroot->right->val != subroot->val)) {
        return false;
      }else {
        res++;
        return true;
      }
    }
    return false;
  }
};
