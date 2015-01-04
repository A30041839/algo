#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > res;
    vector<int> path;
    if (root == NULL){
      return res;
    }
    dfs(root, sum, 0, path, res);
    return res;
  }

  void dfs(TreeNode* root, int sum, int cursum, vector<int>& path, vector<vector<int> >& res){
    cursum += root->val;
    path.push_back(root->val);
    if (root->left == NULL and root->right == NULL){
      if (cursum == sum){
        res.push_back(path);
      }
    }
    if (root->left != NULL){
      dfs(root->left, sum, cursum, path, res);
    }
    if (root->right != NULL){
      dfs(root->right, sum, cursum, path, res);
    }
    path.pop_back();
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(11);
  TreeNode* node4 = new TreeNode(7);
  TreeNode* node5 = new TreeNode(2);
  root->left = node1;
  root->right = node2;
  //node1->left = node3;
  //node3->left = node4;
  //node3->right = node5;
  vector<vector<int> > res = s.pathSum(root, 3);
  for (auto v : res){
    for (auto x : v){
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
