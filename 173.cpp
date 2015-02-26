#include "leetcode.h"

using namespace std;

class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    while (root){
      stk.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stk.empty();
  }

  /** @return the next smallest number */
  int next() {
    if (hasNext()){
      cur = stk.top();
      stk.pop();
      int res = cur->val;
      cur = cur->right;
      while (cur){
        stk.push(cur);
        cur = cur->left;
      }
      return res;
    }else{
      throw exception();
    }
  }

protected:
  stack<TreeNode*> stk;
  TreeNode* cur;

};


int main(){
  TreeNode* root = new TreeNode(4);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(1);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(6);
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node6 = new TreeNode(7);
  root->left = node1;
  root->right = node4;
  node1->left = node2;
  node1->right = node3;
  node4->left = node5;
  node4->right = node6;
  BSTIterator i = BSTIterator(root);
  while (i.hasNext())
    cout << i.next() << ",";
  cout << endl;
  return 0;
}
