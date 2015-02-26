#include "leetcode.h"

using namespace std;

void _inorder(TreeNode* root){
  if (root){
    _inorder(root->left);
    cout << root->val << ",";
    _inorder(root->right);
  }
}

void _postorder(TreeNode* root){
  if (root){
    _postorder(root->left);
    _postorder(root->right);
    cout << root->val << ",";
  }
}
class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return _buildTree(inorder.begin(), postorder.begin(), inorder.size());
  }

  TreeNode* _buildTree(vector<int>::iterator in_it, vector<int>::iterator post_it, size_t n){
    if (!n){
      return nullptr;
    }
    TreeNode* subroot = new TreeNode(*(post_it + n - 1));
    vector<int>::iterator pos = find(in_it, in_it + n, *(post_it + n - 1));
    subroot->left = _buildTree(in_it, post_it, pos - in_it);
    subroot->right = _buildTree(pos + 1, post_it + (pos - in_it), n - (pos - in_it) - 1);
    return subroot;
  }
};

int main(){
  Solution s;
  vector<int> inorder = {2, 1, 5, 3, 7};
  vector<int> postorder = {1, 2, 3, 7, 5};
  TreeNode* root = s.buildTree(inorder, postorder);
  _inorder(root);
  cout << endl;
  _postorder(root);
  cout << endl;
  return 0;
}
