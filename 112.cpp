#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root != NULL){
      return dfs(root, 0, sum);
    }else{
      return false;
    }
  }

  bool dfs(TreeNode* root, int cur, int sum){
    cur += root->val;
    if (root->left == NULL and root->right == NULL){
      return cur == sum;
    }
    bool res1 = false;
    bool res2 = false;
    if (root->left != NULL){
      res1 = dfs(root->left, cur, sum);
    }
    if (root->right != NULL){
      res2 = dfs(root->right, cur, sum);
    }
    return res1 or res2;
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
  if (s.hasPathSum(root, 1)){
    cout << "yes" << endl;
  }
  return 0;
}
