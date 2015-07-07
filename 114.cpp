#include "leetcode.h"

using namespace std;

class Solution {
public:
  void flatten(TreeNode *root) {
    flatten2(root);
  }

  //recursive
  TreeNode* flatten1(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    TreeNode* l = flatten1(root->left);
    TreeNode* r = flatten1(root->right);
    root->left = nullptr;
    root->right = l;
    TreeNode* p = root;
    while (p->right) {
      p = p->right;
    }
    p->right = r;
    return root;
  }

  //iterative
  TreeNode* flatten2(TreeNode *root) {
    stack<TreeNode*> stk;
    TreeNode* ptr = root, *prev = nullptr;
    while (ptr or !stk.empty()) {
      if (ptr) {
        stk.push(ptr->right);
        if (prev) {
          prev->right = ptr;
        }
        prev = ptr;
        TreeNode* tmp = ptr->left;
        ptr->left = nullptr;
        ptr = tmp;
      }else {
        ptr = stk.top();
        stk.pop();
      }
    }
    return root;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(4);
  TreeNode* node4 = new TreeNode(5);
  root->right = node1;
  node1->right = node2;
  node2->right = node3;
  node3->right = node4;
  s.flatten(root);
  while (root){
    cout << root->val << ",";
    root = root->right;
  }
  cout << endl;
  return 0;
}
