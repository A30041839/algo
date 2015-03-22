#include "leetcode.h"

using namespace std;

void inorder(TreeNode* root){
  if (root){
    inorder(root->left);
    cout << root->val << ",";
    inorder(root->right);
  }
}

class Solution {
public:
  void recoverTree(TreeNode *root) {
    recoverTree1(root);
  }

  void recoverTree1(TreeNode* root){

  }

};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(3);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(1);
  root->left = node1;
  root->right = node2;
  s.recoverTree(root);
  inorder(root);
  cout << endl;
  return 0;
}
