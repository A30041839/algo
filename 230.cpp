#include "leetcode.h"

using namespace std;

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    return kthSmallest3(root, k);
  }

  int count(TreeNode* subroot) {
    if (!subroot) {
      return 0;
    }
    return 1 + count(subroot->left) + count(subroot->right);
  }

  int kthSmallest1(TreeNode* root, int k) {
    TreeNode* p = root;
    while (p) {
      int left = count(p->left);
      if (k <= left) {
        p = p->left;
      }else if (k == left + 1) {
        break;
      }else{
        p = p->right;
        k -= (left + 1);
      }
    }
    return p->val;
  }

  int kthSmallest2(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    int i = 0;
    while (root or !stk.empty()) {
      if (root) {
        stk.push(root);
        root = root->left;
      }else {
        root = stk.top();
        stk.pop();
        if (++i == k) {
          break;
        }else {
          root = root->right;
        }
      }
    }
    return root->val;
  }

  int dfs(TreeNode* cur, unordered_map<TreeNode*, int>& mp) {
    if (!cur) {
      return 0;
    }
    int left = dfs(cur->left, mp);
    int right = dfs(cur->right, mp);
    return mp[cur] = 1 + left + right;
  }

  int kthSmallest3(TreeNode* root, int k) {
    unordered_map<TreeNode*, int> mp;
    dfs(root, mp);
    while (root) {
      int lc = mp[root->left];
      if (k <= lc) {
        root = root->left;
      }else if (k == lc + 1) {
        break;
      }else {
        root = root->right;
        k -= (lc + 1);
      }
    }
    return root->val;
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(3);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(1);
  TreeNode* node3 = new TreeNode(4);
  root->left = node1;
  root->right = node3;
  node1->left = node2;
  for (int k = 1; k <= 4; ++k) {
    cout << s.kthSmallest(root, k) << endl;
  }
  return 0;
}
