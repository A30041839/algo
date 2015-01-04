#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root){
      return res;
    }
    stack<TreeNode*> stk;
    TreeNode* p = root;
    while (p or !stk.empty()){
      if (p){
        stk.push(p);
        res.push_back(p->val);
        p = p->left;
      }else{
        p = stk.top();
        stk.pop();
        p = p->right;
      }
    }
    return res;
  }

  vector<int> preorderTraversal2(TreeNode *root) {
    vector<int> res;
    if (!root){
      return res;
    }
    recursive(res, root);
    return res;
  }

  void recursive(vector<int>& res, TreeNode* root){
    res.push_back(root->val);
    if (root->left){
      recursive(res, root->left);
    }
    if (root->right){
      recursive(res, root->right);
    }
  }
  vector<int> preorderTraversal1(TreeNode *root) {
    vector<int> res;
    if (!root){
      return res;
    }
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()){
      TreeNode* p = stk.top();
      stk.pop();
      res.push_back(p->val);
      if (p->right){
        stk.push(p->right);
      }
      if (p->left){
        stk.push(p->left);
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
