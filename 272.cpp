class Solution {
public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    return closestKValues2(root, target, k);
  }

  vector<int> closestKValues1(TreeNode* root, double target, int k) {
    stack<TreeNode*> stk;
    TreeNode* ptr = root;
    auto cmp = [target](int lhs, int rhs) {return fabs(lhs - target) > fabs(rhs - target);};
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    while (ptr or !stk.empty()) {
      if (ptr) {
        pq.push(ptr->val);
        stk.push(ptr->right);
        ptr = ptr->left;
      }else {
        ptr = stk.top();
        stk.pop();
      }
    }
    vector<int> res;
    while (k--) {
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }

  vector<int> closestKValues2(TreeNode* root, double target, int k) {
    queue<int> q;
    vector<int> res;
    dfs(q, root, target, k);
    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }
    return res;
  }

  void dfs(queue<int>& q, TreeNode* subroot, double target, int k) {
    if (!subroot) {
      return;
    }
    dfs(q, subroot->left, target, k);
    if (q.size() < k) {
      q.push(subroot->val);
      dfs(q, subroot->right, target, k);
    }else {
      if (fabs(q.front() - target) > fabs(subroot->val - target)) {
        q.pop();
        q.push(subroot->val);
        dfs(q, subroot->right, target, k);
      }
    }
  }
};
