#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    dfs(res, root, 0);
    return res;
  }

  vector<vector<int> > levelOrder1(TreeNode *root) {
    queue<TreeNode*> q;
    vector<vector<int>> res;
    q.push(root);
    while (!q.empty()) {
      vector<int> level;
      int n = q.size();
      while (n--) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
          level.push_back(cur->val);
          q.push(cur->left);
          q.push(cur->right);
        }
      }
      if (!level.empty()) {
        res.push_back(level);
      }
    }
    return res;
  }

  vector<vector<int> > levelOrder2(TreeNode *root) {
    vector<vector<int>> res;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      TreeNode* cur = q.front().first;
      int level = q.front().second;
      q.pop();
      if (cur) {
        if (res.size() < level + 1) {
          res.resize(level + 1);
        }
        res[level].push_back(cur->val);
        q.push({cur->left, level + 1});
        q.push({cur->right, level + 1});
      }
    }
    return res;
  }

  void dfs(vector<vector<int>>& res, TreeNode* cur, int dep) {
    if (!cur) {
      return;
    }
    if (res.size() < dep + 1) {
      res.resize(dep + 1);
    }
    res[dep].push_back(cur->val);
    dfs(res, cur->left, dep + 1);
    dfs(res, cur->right, dep + 1);
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(4);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  vector<vector<int> > res = s.levelOrder(root);
  for (auto v : res){
    for (auto x : v){
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
