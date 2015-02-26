#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root){
      return res;
    }
    postorderTraversal2(res, root);
    return res;
  }

  void postorderTraversal2(vector<int>& res, TreeNode* root){
    stack<TreeNode*> stk;
    TreeNode* p = root;
    TreeNode* prev = 0;
    while (p or !stk.empty()){
      if (p){
        stk.push(p);
        p = p->left;
      }else{
        p = stk.top();
        if (prev == p->right){
          res.push_back(p->val);
          prev = p;
          p = 0;
          stk.pop();
        }else{
          prev = p->right ? prev : 0;
          p = p->right;
        }
      }
    }
  }

  void postorderTraversal1(vector<int>& res, TreeNode* root){
    stack<TreeNode*> stk1;
    stack<int> stk2;
    TreeNode* p = root;
    stk1.push(p);
    while (!stk1.empty()){
      p = stk1.top();
      stk1.pop();
      stk2.push(p->val);
      if (p->left){
        stk1.push(p->left);
      }
      if (p->right){
        stk1.push(p->right);
      }
    }
    while (!stk2.empty()){
      res.push_back(stk2.top());
      stk2.pop();
    }
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

