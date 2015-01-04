#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == NULL){
      return true;
    }
    if (isBalanced(root->left) and isBalanced(root->right)){
      return abs(getHeight(root->left) - getHeight(root->right)) <= 1;
    }else{
      return false;
    }
  }

  int getHeight(TreeNode* root) {
    if (root != NULL){
      return max(getHeight(root->left), getHeight(root->right)) + 1;
    }else{
      return 0;
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
