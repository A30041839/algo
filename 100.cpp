#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    return isSameTree1(p, q);
  }

  bool isSameTree1(TreeNode *p, TreeNode *q) {
    queue<TreeNode*> q1, q2;
    q1.push(p);
    q2.push(q);
    while (!q1.empty() and !q2.empty()) {
      TreeNode* n1 = q1.front();
      q1.pop();
      TreeNode* n2 = q2.front();
      q2.pop();
      if (!n1 or !n2) {
        if (!n1 and !n2) {
          continue;
        }else {
          return false;
        }
      }
      if (n1->val != n2->val) {
        return false;
      }
      q1.push(n1->left);
      q1.push(n1->right);
      q2.push(n2->left);
      q2.push(n2->right);
    }
    return true;
  }

  bool isSameTree2(TreeNode *p, TreeNode *q) {
    if (!p or !q) {
      return p == q;
    }else {
      return p->val == q->val and isSameTree(p->left, q->left) and
        isSameTree(p->right, q->right);
    }
  }
};

int main(){
  Solution s;
  TreeNode* root1 = new TreeNode(0);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* root2 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(1);
  TreeNode* node5 = new TreeNode(3);
  root1->left = node1;
  root1->right = node2;
  root2->left = node4;
  //root2->right = node5;
  if (s.isSameTree(root1, root2)){
    cout << "Same tree" << endl;
  }
  return 0;
}
