#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root or !p or !q) {
      return nullptr;
    }else {
      return lca1(root, p, q);
    }
  }

  TreeNode* lca1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
      return nullptr;
    }
    if (root == p or root == q) {
      return root;
    }
    TreeNode* l = lca1(root->left, p, q);
    TreeNode* r = lca1(root->right, p, q);
    if (!l) {
      return r;
    }
    if (!r) {
      return l;
    }
    return root;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* n1 = new TreeNode(2);
  TreeNode* n2 = new TreeNode(3);
  root->left = n1;
  root->right = n2;
  cout << s.lowestCommonAncestor(root, root, n2)->val << endl;
  return 0;
}
