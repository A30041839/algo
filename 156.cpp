#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode *upsideDownBinaryTree(TreeNode *root) {
    TreeNode *parent = nullptr, *parent_right = nullptr, *cur = root;
    while (cur) {
      TreeNode* tmp1 = cur->left;
      TreeNode* tmp2 = cur->right;
      cur->left = parent_right;
      cur->right = parent;
      parent = cur;
      cur = tmp1;
      parent_right = tmp2;
    }
    return parent;
  }
};

void preOrder(TreeNode* root) {
  if (root) {
    cout << root->val << ",";
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(4);
  TreeNode* node4 = new TreeNode(5);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node1->right = node4;
  TreeNode* res = s.upsideDownBinaryTree(root);
  preOrder(res);
  cout << endl;
  return 0;
}
