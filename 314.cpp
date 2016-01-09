class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> res1, res2;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      TreeNode* cur = get<0>(q.front());
      int k = get<1>(q.front());
      q.pop();
      if (k >= 0) {
        if (res2.size() < k + 1) {
          res2.resize(k + 1);
        }
        res2[k].push_back(cur->val);
      }else {
        if (res1.size() < -1 * k) {
          res1.resize(-1 * k);
        }
        res1[-1 * k - 1].push_back(cur->val);
      }
      if (cur->left) {
        q.push({cur->left, k - 1});
      }
      if (cur->right) {
        q.push({cur->right, k + 1});
      }
    }
    reverse(res1.begin(), res1.end());
    res1.insert(res1.end(), res2.begin(), res2.end());
    return res1;
  }
};
