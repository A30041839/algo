#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return _buildTree(inorder.begin(), postorder.begin(), inorder.size());
  }

  TreeNode* _buildTree(vector<int>::iterator in_it, vector<int>::iterator post_it, size_t n){
    if (n == 0){
      return nullptr;
    }
    TreeNode* node = new TreeNode(*(post_it + n - 1));
    auto pos = find(in_it, in_it + n, node->val);
    int left = pos - in_it;
    int right = n - left - 1;
    node->left = _buildTree(in_it, post_it, left);
    node->right = _buildTree(pos + 1, post_it + left, right);
    return node;
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
