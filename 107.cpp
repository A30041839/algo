#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    return levelOrderBottom2(root);
  }

  vector<vector<int>> levelOrderBottom1(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      vector<int> level;
      for (int i = 0; i < n; ++i) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
          level.push_back(cur->val);
          q.push(cur->left);
          q.push(cur->right);
        }
      }
      if (!level.empty()) {
        res.insert(res.begin(), level);
      }
    }
    return res;
  }

  vector<vector<int>> levelOrderBottom2(TreeNode* root) {
    vector<vector<int>> res;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      TreeNode* cur = q.front().first;
      int dep = q.front().second;
      q.pop();
      if (cur) {
        if (res.size() < dep + 1) {
          res.resize(dep + 1);
        }
        res[dep].push_back(cur->val);
        q.push({cur->left, dep + 1});
        q.push({cur->right, dep + 1});
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }

  void dfs(vector<vector<int>>& res, TreeNode* root, int dep) {
    if (!root) {
      return;
    }
    if (res.size() < dep + 1) {
      res.resize(dep + 1);
    }
    res[dep].push_back(root->val);
    dfs(res, root->left, dep + 1);
    dfs(res, root->right, dep + 1);
  }
};

int main(){
  Solution s;
  TreeNode* root1 = new TreeNode(0);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(1);
  root1->left = node1;
  root1->right = node2;
  node1->left = node3;
  node1->right = node4;
  vector<vector<int> > res = s.levelOrderBottom(root1);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < res[i].size(); ++j){
      cout << res[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
