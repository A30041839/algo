#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* p = root;
    while (p or !stk.empty()) {
      if (p) {
        stk.push(p);
        p = p->left;
      }else {
        p = stk.top();
        stk.pop();
        res.push_back(p->val);
        p = p->right;
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
  TreeNode* node3 = new TreeNode(4);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  /*    1
   *   / \
   *  2   3
   * /
   * 4
   */
  vector<int> res = s.inorderTraversal(root);
  for (int x : res){
    cout << x << ",";
  }
  cout << endl;
  return 0;
}
