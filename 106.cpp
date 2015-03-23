#include "leetcode.h"

using namespace std;

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
  vector<int> v_inorder = {2, 1, 5, 3, 7};
  vector<int> v_postorder = {1, 2, 3, 7, 5};
  TreeNode* root = s.buildTree(v_inorder, v_postorder);
  inorder(root);
  cout << endl;
  postorder(root);
  cout << endl;
  return 0;
}
