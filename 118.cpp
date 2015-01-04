#include <iostream>
#include <vector>

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
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    if (numRows < 1){
      return res;
    }
    for (int i = 0; i < numRows; ++i){
      vector<int> row;
      for (int k = 0; k < i + 1; ++k){
        if (k == 0 or k == i){
          row.push_back(1);
        }else if (i > 0){
          row.push_back(res[i - 1][k - 1] + res[i - 1][k]);
        }
      }
      res.push_back(row);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<vector<int> > res = s.generate(1);
  for (auto x : res){
    for (int y : x){
      cout << y << ",";
    }
    cout << endl;
  }
  return 0;
}
