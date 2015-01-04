#include <iostream>
#include <vector>
#include <queue>

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
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > res;
    if (root == NULL){
      return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
      int last = q.size();
      vector<int> level;
      for (int i = 0; i < last; ++i){
        TreeNode* ptr = q.front();
        level.push_back(ptr->val);
        q.pop();
        if (ptr->left){
          q.push(ptr->left);
        }
        if (ptr->right){
          q.push(ptr->right);
        }
      }
      res.push_back(level);
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
  vector<vector<int> > res = s.levelOrder(root);
  for (auto v : res){
    for (auto x : v){
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
