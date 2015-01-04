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
  void flatten(TreeNode *root) {
    if (!root){
      return;
    }
    flatten_recursive(root);
  }

  TreeNode* flatten_recursive(TreeNode* p){
    if (p){
      TreeNode* l = flatten_recursive(p->left);
      TreeNode* r = flatten_recursive(p->right);
      if (l){
        p->right = l;
        p->left = NULL;
        while (l->right){
          l = l->right;
        }
        l->right = r;
      }
      return p;
    }else{
      return NULL;
    }
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(4);
  TreeNode* node4 = new TreeNode(5);
  root->right = node1;
  //node1->right = node2;
  //node2->right = node3;
  //node3->right = node4;
  s.flatten(root);
  while (root){
    cout << root->val << ",";
    root = root->right;
  }
  cout << endl;
  return 0;
}
