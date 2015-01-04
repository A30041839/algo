#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > res;
    if (!root){
      return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
      int k = q.size();
      vector<int> v;
      while (k--){
        TreeNode* p = q.front();
        q.pop();
        v.push_back(p->val);
        if (p->left){
          q.push(p->left);
        }
        if (p->right){
          q.push(p->right);
        }
      }
      if (res.size() & 1){
        reverse(v.begin(), v.end());
      }
      res.push_back(v);
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
  vector<vector<int> > res = s.zigzagLevelOrder(root);
  for (auto x : res){
    for (int y : x){
      cout << y << ",";
    }
    cout << endl;
  }
  return 0;
}
