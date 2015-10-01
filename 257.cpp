#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    dfs(res, "", root);
    return res;
  }

  void dfs(vector<string>& res, string path, TreeNode* subroot) {
    if (!subroot) {
      return;
    }
    if (!subroot->left and !subroot->right) {
      path.append(to_string(subroot->val));
      res.push_back(path);
      return;
    }
    dfs(res, path + to_string(subroot->val) + "->", subroot->left);
    dfs(res, path + to_string(subroot->val) + "->", subroot->right);
  }
};
