#include "leetcode.h"

using namespace std;

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &num) {
    if (!num.size()){
      return nullptr;
    }
    return sortedArrayToBST1(num, 0, num.size() - 1);
  }
  TreeNode* sortedArrayToBST1(vector<int>& num, int low, int high){
    if (low <= high){
      int mid = (low + high) / 2;
      TreeNode* node = new TreeNode(num[mid]);
      node->left = sortedArrayToBST1(num, low, mid - 1);
      node->right = sortedArrayToBST1(num, mid + 1, high);
      return node;
    }else{
      return nullptr;
    }
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
