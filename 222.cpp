#include "leetcode.h"

using namespace std;

class Solution {
private:
  int leftHeight(TreeNode* ptr) {
    int height = 0;
    while (ptr) {
      ptr = ptr->left;
      height++;
    }
    return height;
  }

  int rightHeight(TreeNode* ptr) {
    int height = 0;
    while (ptr) {
      ptr = ptr->right;
      height++;
    }
    return height;
  }

public:
  int countNodes(TreeNode* root) {
    return countNodes1(root);
  }

  int countNodes1(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int lh = leftHeight(root);
    int rh = rightHeight(root);
    if (lh == rh) {
      return pow(2, lh) - 1;
    }else {
      return 1 + countNodes1(root->left) + countNodes1(root->right);
    }
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(0);
  TreeNode* n1 = new TreeNode(0);
  TreeNode* n2 = new TreeNode(0);
  TreeNode* n3 = new TreeNode(0);
  TreeNode* n4 = new TreeNode(0);
  TreeNode* n5 = new TreeNode(0);
  root->left = n1;
  root->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->left = n5;
  cout << s.countNodes(root) << endl;
  return 0;
}
