#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
  }

  TreeNode* dfs(vector<int>& nums, int beg, int end) {
    if (beg > end) {
      return nullptr;
    }
    int mid = beg + (end - beg) / 2;
    TreeNode* subroot = new TreeNode(nums[mid]);
    subroot->left = dfs(nums, beg, mid - 1);
    subroot->right = dfs(nums, mid + 1, end);
    return subroot;
  }
};

void traverse(TreeNode* p){
  if (p->left){
    traverse(p->left);
  }
  cout << p->val << ",";
  if (p->right){
    traverse(p->right);
  }
}

int main(){
  Solution s;
  vector<int> v = {1, 2, 3, 4, 5};
  TreeNode* p = s.sortedArrayToBST(v);
  traverse(p);
  return 0;
}
