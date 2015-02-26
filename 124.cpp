#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    if (!root){
      return 0;
    }
    int maxSum = INT_MIN;
    maxPathSum1(root, maxSum);
    return maxSum;
  }
  
  int maxPathSum1(TreeNode* root, int& maxSum){
    if (!root->left and !root->right){
      maxSum = max(maxSum, root->val);
      return root->val;
    }
    int leftMaxSum = 0, rightMaxSum = 0;
    if (root->left){
      leftMaxSum = maxPathSum1(root->left, maxSum);
      leftMaxSum = leftMaxSum > 0 ? leftMaxSum : 0;
    }
    if (root->right){
      rightMaxSum = maxPathSum1(root->right, maxSum);
      rightMaxSum = rightMaxSum > 0 ? rightMaxSum : 0;
    }
    int sum = root->val + leftMaxSum + rightMaxSum;
    maxSum = max(maxSum, sum);
    return leftMaxSum > rightMaxSum ? root->val + leftMaxSum : root->val + rightMaxSum;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(-2);
  TreeNode* node2 = new TreeNode(3);
  //TreeNode* node4 = new TreeNode(1);
  //TreeNode* node5 = new TreeNode(3);
  root->left = node1;
  root->right = node2;
  cout << s.maxPathSum(root) << endl;
  return 0;
}
