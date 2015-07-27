#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    return dfs(1, n);
  }

  vector<TreeNode *> dfs(int low, int high) {
    if (low > high) {
      return {nullptr};
    }
    vector<TreeNode*> res;
    for (int r = low; r <= high; ++r) {
      auto lsub = dfs(low, r - 1);
      auto rsub= dfs(r + 1, high);
      for (auto& lt : lsub) {
        for (auto& rt : rsub) {
          TreeNode* root = new TreeNode(r);
          root->left = lt;
          root->right = rt;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<TreeNode* > res = s.generateTrees(3);
  cout << res.size() << endl;
  return 0;
}
