#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    return invertTree3(root);
  }

  TreeNode* invertTree1(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    TreeNode* tmp = root->left;
    root->left = invertTree1(root->right);
    root->right = invertTree1(tmp);
    return root;
  }

  TreeNode* invertTree2(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    swap(root->left, root->right);
    invertTree2(root->left);
    invertTree2(root->right);
    return root;
  }

  TreeNode* invertTree3(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
          swap(cur->left, cur->right);
          q.push(cur->left);
          q.push(cur->right);
        }
      }
    }
    return root;
  }
};

int main() {
  return 0;
}
