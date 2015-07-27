#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root){
      return {};
    }else {
      return postorderTraversal1(root);
    }
  }

  vector<int> postorderTraversal1(TreeNode* root){
    stack<TreeNode*> stk;
    vector<int> res;
    TreeNode* prev = nullptr, *cur = root;
    while (cur or !stk.empty()) {
      if (cur) {
        stk.push(cur);
        cur = cur->left;
      }else {
        cur = stk.top();
        if (prev == cur->right) {
          //return from right subtree
          res.push_back(cur->val);
          stk.pop();
          prev = cur;
          //go to upper level
          cur = nullptr;
        }else {
          cur = cur->right;
          if (!cur) {
            prev = nullptr;
          }
        }
      }
    }
    return res;
  }

  vector<int> postorderTraversal2(TreeNode* root){
    stack<TreeNode*> stk;
    stack<int> visit;
    vector<int> res;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* cur = stk.top();
      stk.pop();
      visit.push(cur->val);
      if (cur->left) {
        stk.push(cur->left);
      }
      if (cur->right) {
        stk.push(cur->right);
      }
    }
    while (!visit.empty()) {
      res.push_back(visit.top());
      visit.pop();
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
  vector<int> res = s.postorderTraversal(root);
  for (int x : res){
    cout << x << ",";
  }
  cout << endl;
  return 0;
}

