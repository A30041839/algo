#include "leetcode.h"

using namespace std;

class Solution {
public:
  void recoverTree(TreeNode *root) {
    recoverTree1(root);
  }

  void dfs(TreeNode* root, TreeNode*& p1, TreeNode*&p2, TreeNode*& prev) {
    if (!root) {
      return;
    }
    dfs(root->left, p1, p2, prev);
    if (prev and prev->val >= root->val) {
      if (!p1) {
        p1 = prev;
      }
      p2 = root;
    }
    prev = root;
    dfs(root->right, p1, p2, prev);
  }

  //O(log(n)) space
  void recoverTree1(TreeNode *root) {
    TreeNode *p1 = nullptr, *p2 = nullptr, *prev = nullptr;
    dfs(root, p1, p2, prev);
    if (p1 and p2) {
      swap(p1->val, p2->val);
    }
  }

  //O(1) space: threaded BST
  void recoverTree2(TreeNode *root) {
  }

  //O(1) space: morris algorithm
  void recoverTree3(TreeNode *root) {
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(3);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  root->left = node1;
  root->right = node2;
  s.recoverTree(root);
  inorder(root);
  cout << endl;
  return 0;
}
