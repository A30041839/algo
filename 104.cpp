#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxDepth(TreeNode *root) {
    return maxDepth4(root);
  }

  void maxDepth1(TreeNode *root, int dep, int& maxDep) {
    if (!root) {
      return;
    }
    if (!root->left and !root->right) {
      maxDep = max(maxDep, dep);
      return;
    }
    maxDepth1(root->left, dep + 1, maxDep);
    maxDepth1(root->right, dep + 1, maxDep);
  }

  int maxDepth2(TreeNode *root) {
    if (!root){
      return 0;
    }
    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);
    return max(left_height, right_height) + 1;
  }

  int maxDepth3(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while (!q.empty()) {
      int n = q.size();
      bool f = false;
      while (n--) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur) {
          f = true;
          q.push(cur->left);
          q.push(cur->right);
        }
      }
      if (f) {
        res++;
      }
    }
    return res;
  }

  int maxDepth4(TreeNode* root) {
    if (!root) {
      return 0;
    }
    stack<TreeNode*> stk;
    TreeNode* cur = root, *prev = nullptr;
    int res = 0;
    while (cur or !stk.empty()) {
      if (cur) {
        stk.push(cur);
        cur = cur->left;
      }else {
        res = max(res, (int)stk.size());
        if (prev == stk.top()->right) {
          prev = stk.top();
          stk.pop();
        }else {
          cur = stk.top()->right;
          if (!cur) {
            prev = nullptr;
          }
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(0);
  TreeNode* node1 = new TreeNode(0);
  TreeNode* node2 = new TreeNode(0);
  TreeNode* node3 = new TreeNode(0);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  cout << s.maxDepth(root) << endl;
  return 0;
}
