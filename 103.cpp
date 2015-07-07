#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    return zigzagLevelOrder3(root);
  }

  vector<vector<int>> zigzagLevelOrder1(TreeNode *root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> res;
    stack<TreeNode*> stk[2];
    int cur = 0;
    stk[cur].push(root);
    while (!stk[cur].empty()) {
      vector<int> level;
      while (!stk[cur].empty()) {
        TreeNode* node = stk[cur].top();
        stk[cur].pop();
        level.push_back(node->val);
        if (!cur) {
          if (node->left) {
            stk[1 - cur].push(node->left);
          }
          if (node->right) {
            stk[1 - cur].push(node->right);
          }
        }else {
          if (node->right) {
            stk[1 - cur].push(node->right);
          }
          if (node->left) {
            stk[1 - cur].push(node->left);
          }
        }
      }
      res.push_back(level);
      cur = 1 - cur;
    }
    return res;
  }

  vector<vector<int>> zigzagLevelOrder2(TreeNode *root) {
    if (!root) {
      return {};
    }
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    int level = 0;
    while (!q.empty()) {
      level++;
      int k = q.size();
      vector<int> vec;
      for (int i = 0; i < k; ++i) {
        TreeNode* node = q.front();
        vec.push_back(node->val);
        q.pop();
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      if (!(level & 1)) {
        reverse(vec.begin(), vec.end());
      }
      res.push_back(vec);
    }
    return res;
  }

  void dfs(TreeNode* root, vector<vector<int>>& res, int dep) {
    if (!root) {
      return;
    }
    if (res.size() < dep + 1) {
      res.resize(dep + 1);
    }
    res[dep].push_back(root->val);
    dfs(root->left, res, dep + 1);
    dfs(root->right, res, dep + 1);
  }

  vector<vector<int>> zigzagLevelOrder3(TreeNode *root) {
    vector<vector<int>> res;
    dfs(root, res, 0);
    for (int i = 0; i < res.size(); ++i) {
      if (i & 1) {
        reverse(res[i].begin(), res[i].end());
      }
    }
    return res;
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
  /*    1
   *   / \
   *  2   3
   * /
   * 4
   */
  vector<vector<int> > res = s.zigzagLevelOrder(root);
  for (auto x : res){
    for (int y : x){
      cout << y << ",";
    }
    cout << endl;
  }
  return 0;
}
