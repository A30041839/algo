#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    if (root == NULL){
      return res;
    }
    stack<vector<int> > res1;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
      vector<int> vec;
      int cur = 0;
      int last = q.size();
      while (cur < last){
        TreeNode* p = q.front();
        q.pop();
        vec.push_back(p->val);
        if (p->left){
          q.push(p->left);
        }
        if (p->right){
          q.push(p->right);
        }
        cur++;
      }
      res1.push(vec);
    }
    while (!res1.empty()){
      res.push_back(res1.top());
      res1.pop();
    }
    return res;
  }
};

int main(){
  Solution s;
  TreeNode* root1 = new TreeNode(0);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(1);
  root1->left = node1;
  root1->right = node2;
  node1->left = node3;
  node1->right = node4;
  vector<vector<int> > res = s.levelOrderBottom(root1);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < res[i].size(); ++j){
      cout << res[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
