#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }else {
      //return isSymmetric1(root->left, root->right);
      return isSymmetric4(root);
    }
  }

  bool isSymmetric1(TreeNode* subroot1, TreeNode* subroot2) {
    if (!subroot1 or !subroot2) {
      return subroot1 == subroot2;
    }
    if (subroot1->val != subroot2->val) {
      return false;
    }
    return isSymmetric1(subroot1->left, subroot2->right) and
      isSymmetric1(subroot1->right, subroot2->left);
  }

  bool isSymmetric2(TreeNode *root) {
    stack<TreeNode*> stk1, stk2;
    stk1.push(root);
    stk2.push(root);
    while (!stk1.empty() and !stk2.empty()) {
      TreeNode* p1 = stk1.top();
      stk1.pop();
      TreeNode* p2 = stk2.top();
      stk2.pop();
      if (!p1 or !p2) {
        if (p1 != p2) {
          return false;
        }
      }else {
        if (p1->val != p2->val) {
          return false;
        }
        stk1.push(p1->right);
        stk1.push(p1->left);
        stk2.push(p2->left);
        stk2.push(p2->right);
      }
    }
    return true;
  }

  bool isSymmetric3(TreeNode *root) {
    stack<TreeNode*> stk1, stk2;
    TreeNode* p1 = root, *p2 = root;
    while ((p1 or !stk1.empty()) and (p2 or !stk2.empty())) {
      if (p1 or p2) {
        if (!p1 or !p2) {
          return false;
        }
        if (p1->val != p2->val) {
          return false;
        }
        stk1.push(p1->right);
        p1 = p1->left;
        stk2.push(p2->left);
        p2 = p2->right;
      }else {
        p1 = stk1.top();
        stk1.pop();
        p2 = stk2.top();
        stk2.pop();
      }
    }
    return true;
  }

  bool isSymmetric4(TreeNode *root) {
    queue<TreeNode*> q1, q2;
    q1.push(root);
    q2.push(root);
    while (!q1.empty() and !q2.empty()) {
      int n1 = q1.size();
      for (int i = 0; i < n1; ++i) {
        TreeNode* p1 = q1.front();
        q1.pop();
        TreeNode* p2 = q2.front();
        q2.pop();
        if (!p1 or !p2) {
          if (p1 != p2) {
            return false;
          }
        }else {
          if (p1->val != p2->val) {
            return false;
          }
          q1.push(p1->left);
          q1.push(p1->right);
          q2.push(p2->right);
          q2.push(p2->left);
        }
      }
    }
    return true;
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(3);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node2->right = node4;
  if (s.isSymmetric(root)){
    cout << "yes" << endl;
  }
  return 0;
}

