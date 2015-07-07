#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    return rightSideView3(root);
  }

  vector<int> rightSideView1(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while (!q.empty()) {
      int n = q.size();
      TreeNode* last = nullptr;
      while (n--) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
          q.push(cur->left);
          q.push(cur->right);
          last = cur;
        }
      }
      if (last) {
        res.push_back(last->val);
      }
    }
    return res;
  }

  vector<int> rightSideView2(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    vector<int> res;
    while (!q.empty()) {
      TreeNode* cur = q.front().first;
      int dep = q.front().second;
      q.pop();
      if (cur) {
        if (res.size() < dep + 1) {
          res.resize(dep + 1);
        }
        res[dep] = cur->val;
        q.push({cur->left, dep + 1});
        q.push({cur->right, dep + 1});
      }
    }
    return res;
  }

  void dfs(vector<int>& res, TreeNode* cur, int dep) {
    if (!cur) {
      return;
    }
    if (res.size() < dep + 1) {
      res.resize(dep + 1);
    }
    res[dep] = cur->val;
    dfs(res, cur->left, dep + 1);
    dfs(res, cur->right, dep + 1);
  }

  vector<int> rightSideView3(TreeNode* root) {
    vector<int> res;
    dfs(res, root, 0);
    return res;
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(4);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  auto res = s.rightSideView(root);
  for (auto x : res) {
    cout << x << endl;
  }
  return 0;
}
