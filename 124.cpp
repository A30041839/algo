#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int res = INT_MIN;
    maxPathSum1(root, res);
    return res;
  }

  int maxPathSum1(TreeNode *root, int& res) {
    if (!root) {
      return INT_MIN;
    }
    int lmax = maxPathSum1(root->left, res);
    int rmax = maxPathSum1(root->right, res);
    res = max(res, max(lmax, 0) + max(rmax, 0) + root->val);
    return max(max(lmax, rmax), 0) + root->val;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  //TreeNode* node4 = new TreeNode(1);
  //TreeNode* node5 = new TreeNode(3);
  root->left = node1;
  root->right = node2;
  cout << s.maxPathSum(root) << endl;
  return 0;
}
