#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL or q == NULL){
      return p == q;
    }else{
      return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
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
