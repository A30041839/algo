#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    return bfs1(root, sum);
  }

  void dfs1(vector<vector<int>>& res, vector<int>&path, TreeNode* cur,
    int remain) {
    if (!cur) {
      return;
    }
    remain -= cur->val;
    path.push_back(cur->val);
    if (!cur->left and !cur->right and !remain) {
      res.push_back(path);
      path.pop_back();
      return;
    }
    dfs1(res, path, cur->left, remain);
    dfs1(res, path, cur->right, remain);
    path.pop_back();
  }

  vector<vector<int> > dfs2(TreeNode *root, vector<int>& path, int remain) {
    vector<vector<int>> res;
    if (!root) {
      return {};
    }
    remain -= root->val;
    path.push_back(root->val);
    if (!root->left and !root->right and !remain) {
      res = {path};
      path.pop_back();
      return res;
    }
    auto lres = dfs2(root->left, path, remain);
    auto rres = dfs2(root->right, path, remain);
    for (auto& v : lres) {
      res.push_back(v);
    }
    for (auto& v : rres) {
      res.push_back(v);
    }
    path.pop_back();
    return res;
  }

  //bfs
  vector<vector<int> > bfs1(TreeNode *root, int sum) {
    if (!root) {
      return {};
    }
    vector<vector<int>> res;
    unordered_map<TreeNode*, TreeNode*> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, root->val});
    mp[root] = nullptr;
    while (!q.empty()) {
      TreeNode* cur = q.front().first;
      int cursum = q.front().second;
      q.pop();
      if (!cur->left and !cur->right and cursum == sum) {
        vector<int> path;
        TreeNode* ptr = cur;
        while (ptr) {
          path.push_back(ptr->val);
          ptr = mp[ptr];
        }
        reverse(path.begin(), path.end());
        res.push_back(path);
      }
      if (cur->left) {
        q.push({cur->left, cursum + cur->left->val});
        mp[cur->left] = cur;
      }
      if (cur->right) {
        q.push({cur->right, cursum + cur->right->val});
        mp[cur->right] = cur;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(11);
  TreeNode* node4 = new TreeNode(7);
  TreeNode* node5 = new TreeNode(2);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node3->left = node4;
  node3->right = node5;
  vector<vector<int> > res = s.pathSum(root, 3);
  for (auto v : res){
    for (auto x : v){
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
