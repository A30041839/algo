#include "leetcode.h"

using namespace std;

class Solution {
public:
  int sumNumbers(TreeNode* root) {
    return sumNumbers3(root);
  }

  void dfs1(TreeNode* cur, int& sum, int num) {
    if (!cur) {
      return;
    }
    num = num * 10 + cur->val;
    if (!cur->left and !cur->right) {
      sum += num;
      return;
    }
    dfs1(cur->left, sum, num);
    dfs1(cur->right, sum, num);
  }

  int sumNumbers1(TreeNode* root) {
    int res = 0;
    dfs1(root, res, 0);
    return res;
  }

  int dfs2(TreeNode* cur, int num) {
    if (!cur) {
      return 0;
    }
    num = num * 10 + cur->val;
    if (!cur->left and !cur->right) {
      return num;
    }
    int lsum = dfs2(cur->left, num);
    int rsum = dfs2(cur->right, num);
    return lsum + rsum;
  }

  int sumNumbers2(TreeNode* root) {
    return dfs2(root, 0);
  }

  //bfs
  int sumNumbers3(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int res = 0;
    while (!q.empty()) {
      int n = q.size();
      while (n--) {
        TreeNode* cur = q.front().first;
        int val = q.front().second;
        q.pop();
        if (cur) {
          val = val * 10 + cur->val;
          if (!cur->left and !cur->right) {
            res += val;
          }else {
            q.push({cur->left, val});
            q.push({cur->right, val});
          }
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  root->left = node1;
  root->right = node2;
  cout << s.sumNumbers(root) << endl;
  return 0;
}
