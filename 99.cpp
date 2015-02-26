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
    if (root){
      if (root->right and root->val > root->right->val){
        swap(root->val, root->right->val);
        return;
      }else if (root->left and root->val < root->left->val){
        swap(root->val, root->left->val);
        return;
      }
      recoverTree1(root->left);
      recoverTree1(root->right);
    }
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
