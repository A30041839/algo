#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    return generateTrees1(1, n);
  }
  
  vector<TreeNode* > generateTrees1(int s, int e) {
    if (s > e){
      return {nullptr};
    }
    vector<TreeNode* > res;
    for (int i = s; i <= e; ++i){
      vector<TreeNode* > left_subtrees = generateTrees1(s, i - 1);
      vector<TreeNode* > right_subtrees = generateTrees1(i + 1, e);
      for (TreeNode* l : left_subtrees){
        for (TreeNode* r : right_subtrees){
          TreeNode* new_node = new TreeNode(i);
          new_node->left = l;
          new_node->right = r;
          res.push_back(new_node);
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<TreeNode* > res = s.generateTrees(3);
  cout << res[0]->right->val << endl;
  cout << res[1]->right->val << endl;
  return 0;
}
