#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minDepth(TreeNode *root) {
    return minDepth1(root);
  }

  int minDepth1(TreeNode *root) {
    if (!root) {
      return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while (!q.empty()) {
      int n = q.size();
      res++;
      while (n--) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
          if (!cur->left and !cur->right) {
            return res;
          }
          q.push(cur->left);
          q.push(cur->right);
        }
      }
    }
  }

  void minDepth2(TreeNode *root, int dep, int& minDep) {
    if (!root or dep >= minDep) {
      return;
    }
    if (!root->left and !root->right) {
      minDep = min(minDep, dep);
      return;
    }
    minDepth2(root->left, dep + 1, minDep);
    minDepth2(root->right, dep + 1, minDep);
  }
};

class Solution1 {
public:
  int minDepth(TreeNode *root) {
    if (root == NULL){
      return 0;
    }
    int res = INT_MAX;
    dfs(root, res, 1);
    return res;
  }

  void dfs(TreeNode* root, int& minDepth, int n){
    if (root->left == NULL and root->right == NULL){
      minDepth = minDepth <= n ? minDepth : n;
      return;
    }
    if (root->left != NULL){
      dfs(root->left, minDepth, n + 1);
    }
    if (root->right != NULL){
      dfs(root->right, minDepth, n + 1);
    }
  }
};

int main(){
  Solution s;
  TreeNode* root1 = new TreeNode(0);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(1);
  //root1->left = node1;
  //root1->right = node2;
  //node1->left = node3;
  //node1->right = node4;
  cout << s.minDepth(root1) << endl;
  return 0;
}
