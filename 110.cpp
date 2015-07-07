#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    return isBalanced1(root) == -1 ? false : true;
  }

  int isBalanced1(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int lh = isBalanced1(root->left);
    int rh = isBalanced1(root->right);
    if (lh == -1 or rh == -1 or abs(lh - rh) > 1) {
      return -1;
    }else {
      return max(lh, rh) + 1;
    }
  }
};


int main(){
  Solution s;
  TreeNode* root = new TreeNode(0);
  TreeNode* node1 = new TreeNode(0);
  TreeNode* node2 = new TreeNode(0);
  TreeNode* node3 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(0);
  TreeNode* node5 = new TreeNode(0);
  root->left = node1;
  node1->left = node2;
  root->right = node3;

  if (s.isBalanced(root)){
    cout << "Tree is balanced!" << endl;
  }

  return 0;
}
