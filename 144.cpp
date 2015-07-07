#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    return preorderTraversal2(root);
  }

  vector<int> preorderTraversal1(TreeNode *root) {
    stack<TreeNode*> stk;
    TreeNode* ptr = root;
    vector<int> res;
    while (ptr or !stk.empty()) {
      if (ptr) {
        res.push_back(ptr->val);
        stk.push(ptr);
        ptr = ptr->left;
      }else {
        ptr = stk.top()->right;
        stk.pop();
      }
    }
    return res;
  }

  vector<int> preorderTraversal2(TreeNode *root) {
    if (!root) {
      return {};
    }
    vector<int> res;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* cur = stk.top();
      stk.pop();
      res.push_back(cur->val);
      if (cur->right) {
        stk.push(cur->right);
      }
      if (cur->left) {
        stk.push(cur->left);
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
  vector<int> res = s.preorderTraversal(root);
  for (int x : res){
    cout << x << ",";
  }
  cout << endl;
  return 0;
}
