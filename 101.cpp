#include "leetcode.h"

using namespace std;

class Solution1 {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL){
      return true;
    }
    return recursive(root->left, root->right);
  }

  bool recursive(TreeNode* node1, TreeNode* node2){
    if (node1 == NULL or node2 == NULL){
      return node1 == node2;
    }
    if (node1->val == node2->val){
      return recursive(node1->left, node2->right) and recursive(node1->right, node2->left);
    }else{
      return false;
    }
  }
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL){
      return true;
    }
    stack<TreeNode*> s1, s2;
    s1.push(root);
    s2.push(root);
    while (!s1.empty() and !s2.empty()){
      TreeNode* p1 = s1.top();
      TreeNode* p2 = s2.top();
      s1.pop();
      s2.pop();
      if (p1 == NULL or p2 == NULL){
        if (p1 != p2){
          return false;
        }
      }else{
        if (p1->val != p2->val){
          return false;
        }
        s1.push(p1->right);
        s1.push(p1->left);
        s2.push(p2->left);
        s2.push(p2->right);
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

