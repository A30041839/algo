#include <iostream>
#include <vector>
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
  void nextPermutation(vector<int> &num) {
  }
};

int main(){
  Solution s;
  //vector<int> v = {5, 4, 1, 3, 2};
  //vector<int> v = {5, 4, 3, 2, 1};
  vector<int> v = {1, 2, 3, 4, 5};
  s.nextPermutation(v);
  for (int i = 0; i < v.size(); ++i){
    cout << v[i] << ",";
  }
  cout << endl;
  return 0;
}
