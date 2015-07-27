#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root or !p or !q) {
      return nullptr;
    }else {
      if (p->val > q->val) {
        swap(p, q);
      }
      return lca(root, p, q);
    }
  }

  TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root or root == p or root == q) {
      return root;
    }
    if (p->val < root->val and q->val > root->val) {
      return root;
    }
    if (q->val < root->val) {
      return lca(root->left, p, q);
    }else {
      return lca(root->right, p, q);
    }
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(2);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(3);
  root->left = n1;
  root->right = n2;
  cout << s.lowestCommonAncestor(root, root, n2)->val << endl;
  return 0;
}
