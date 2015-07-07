#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    return hasPathSum2(root, sum);
  }

  bool dfs(TreeNode* root, int cur, int sum) {
    if (!root) {
      return false;
    }
    cur += root->val;
    if (!root->left and !root->right) {
      return cur == sum;
    }
    if (dfs(root->left, cur, sum)) {
      return true;
    }else {
      return dfs(root->right, cur, sum);
    }
  }

  bool hasPathSum1(TreeNode *root, int sum) {
    return dfs(root, 0, sum);
  }

  //bfs
  bool hasPathSum2(TreeNode *root, int sum) {
    if (!root) {
      return false;
    }
    queue<pair<TreeNode*, int>> q;
    q.push({root, root->val});
    while (!q.empty()) {
      TreeNode* cur = q.front().first;
      int val = q.front().second;
      q.pop();
      if (val == sum and !cur->left and !cur->right) {
        return true;
      }
      if (cur->left) {
        q.push({cur->left, val + cur->left->val});
      }
      if (cur->right) {
        q.push({cur->right, val + cur->right->val});
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(5);
  TreeNode* node3 = new TreeNode(11);
  TreeNode* node4 = new TreeNode(7);
  TreeNode* node5 = new TreeNode(2);
  root->left = node1;
  //root->right = node2;
  //node1->left = node3;
  //node3->left = node4;
  //node3->right = node5;
  if (s.hasPathSum(root, 3)){
    cout << "yes" << endl;
  }
  return 0;
}
