#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == NULL){
      return 0;
    }
    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
      int cur = 0;
      int last = q.size();
      res++;
      while (cur < last){
        TreeNode* tmp = q.front();
        q.pop();
        if (tmp->left == NULL and tmp->right == NULL){
          return res;
        }
        if (tmp->left != NULL){
          q.push(tmp->left);
        }
        if (tmp->right != NULL){
          q.push(tmp->right);
        }
        cur++;
      }
    }
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
