#include "leetcode.h"

using namespace std;

class Solution {
public:
  void recoverTree(TreeNode *root) {
    recoverTree1(root);
  }

  void recoverTree1(TreeNode* root){
    if (!root or (!root->left and !root->right)) {
      return;
    }
    vector<pair<int, TreeNode*> > v;
    inorder(root, v);
    int len = v.size();
    TreeNode* p1 = 0, *p2 = 0;
    for (int i = 0; i < len - 1; ++i) {
      if (v[i].first > v[i + 1].first) {
        p1 = v[i].second;
        break;
      }
    }
    for (int j = len - 1; j > 0; --j) {
      if (v[j].first < v[j - 1].first) {
        p2 = v[j].second;
        break;
      }
    }
    swap(p1->val, p2->val);
  }

  void inorder(TreeNode* root, vector<pair<int, TreeNode*> >& v) {
    if (root) {
      inorder(root->left, v);
      v.push_back(make_pair(root->val, root));
      inorder(root->right, v);
    }
  }

};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(2);
  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2 = new TreeNode(1);
  root->left = node1;
  root->right = node2;
  s.recoverTree(root);
  inorder(root);
  cout << endl;
  return 0;
}
