#include "leetcode.h"

using namespace std;

void preorderTraverse(TreeNode* root){
  if (root){
    cout << root->val << ",";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
  }
}

void inorderTraverse(TreeNode* root){
  if (root){
    inorderTraverse(root->left);
    cout << root->val << ",";
    inorderTraverse(root->right);
  }
}

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return _buildTree(preorder.begin(), inorder.begin(), preorder.size());
  }

  TreeNode* _buildTree(vector<int>::iterator pre_it, vector<int>::iterator in_it, size_t n){
    if (n == 0){
      return nullptr;
    }
    TreeNode* root = new TreeNode(*pre_it);
    vector<int>::iterator pos = find(in_it, in_it + n, *pre_it);
    root->left = _buildTree(pre_it + 1, in_it, pos - in_it);
    root->right = _buildTree(pre_it + 1 + (pos - in_it), pos + 1, n - (pos - in_it) - 1);
    return root;
  }

};

int main(){
  Solution s;
  vector<int> preorder = {1,5,2,7,4};
  vector<int> inorder = {5,2,1,4,7};
  TreeNode* root = s.buildTree(preorder, inorder);
  preorderTraverse(root);
  cout << endl;
  inorderTraverse(root);
  cout << endl;
  return 0;
}
