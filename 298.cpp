class Solution {
public:
  int longestConsecutive(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;
  }

  int dfs(TreeNode* root, int& res) {
    if (!root) {
      return 0;
    }
    int l = dfs(root->left, res);
    if (!root->left or root->left->val == root->val + 1) {
      l++;
    }else {
      l = 1;
    }
    int r = dfs(root->right, res);
    if (!root->right or root->right->val == root->val + 1) {
      r++;
    }else {
      r = 1;
    }
    res = max(res, max(l, r));
    return max(l, r);
  }
};
