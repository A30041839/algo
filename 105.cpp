#include "leetcode.h"

using namespace std;

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
  vector<int> v_preorder = {1,5,2,7,4};
  vector<int> v_inorder = {5,2,1,4,7};
  TreeNode* root = s.buildTree(v_preorder, v_inorder);
  preorder(root);
  cout << endl;
  inorder(root);
  cout << endl;
  return 0;
}
