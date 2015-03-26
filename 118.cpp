#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > res;
    for (int i = 0; i < numRows; ++i){
      vector<int> row;
      for (int k = 0; k < i + 1; ++k){
        if (k == 0 or k == i){
          row.push_back(1);
        }else {
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
  vector<vector<int> > res = s.generate(3);
  for (auto x : res){
    for (int y : x){
      cout << y << ",";
    }
    cout << endl;
  }
  return 0;
}
