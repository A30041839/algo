#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (root == NULL){
      return true;
    }
    if (root->left and root->left->val >= root->val){
      return false;
    }
    if (root->right and root->right->val <= root->val){
      return false;
    }
    if (root->left and getLeftMax(root->left) >= root->val){
      return false;
    }
    if (root->right and getRightMin(root->right) <= root->val){
      return false;
    }
    return isValidBST(root->left) and isValidBST(root->right);
  }

  int getLeftMax(TreeNode *node){
    while (node->right){
      node = node->right;
    }
    return node->val;
  }

  int getRightMin(TreeNode *node){
    while (node->left){
      node = node->left;
    }
    return node->val;
  }
};

class Solution1 {
public:
  bool isValidBST(TreeNode *root) {
    if (root == NULL){
      return true;
    }
    bool res = true;
    bool start = true;
    int pre = INT_MIN;
    validBST(root, pre, res, start);
    return res;
  }

  void validBST(TreeNode* root, int& pre, bool& res, bool& start){
    if (root->left){
      validBST(root->left, pre, res, start);
    }
    if (root->val <=  pre){
      if (!start){
        res = false;
        return;
      }
    }
    pre = root->val;
    start = false;
    if (root->right){
      validBST(root->right, pre, res, start);
    }
  }
};

int main(){
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  //root->left = node1;
  //root->right = node2;
  Solution s;
  if (s.isValidBST(root)){
    cout << "yes" << endl;
  }
  return 0;
}
