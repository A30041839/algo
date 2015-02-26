#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root){
      return 0;
    }
    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);
    return max(left_height, right_height) + 1;
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
