#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode *upsideDownBinaryTree(TreeNode *root) {
    return upsideDownBinaryTree1(root);
  }

  //iterative
  TreeNode *upsideDownBinaryTree1(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    TreeNode* ptr = root, *new_root = nullptr;
    stack<TreeNode*> stk;
    while (ptr->left) {
      stk.push(ptr);
      ptr = ptr->left;
    }
    new_root = ptr;
    while (!stk.empty()) {
      TreeNode* tmp = stk.top();
      stk.pop();
      ptr->left = tmp->right;
      ptr->right = tmp;
      ptr = tmp;
    }
    root->left = root->right = nullptr;
    return new_root;
  }

  //recursive
  TreeNode *upsideDownBinaryTree2(TreeNode *root) {
    if (!root or !root->left) {
      return root;
    }
    TreeNode* l = upsideDownBinaryTree2(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = nullptr;
    return l;
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
