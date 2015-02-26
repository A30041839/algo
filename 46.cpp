#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    return permute1(num.begin(), num.end());
  }

  vector<vector<int> > permute1(vector<int>::iterator begin, vector<int>::iterator end) {
    vector<vector<int> > res;
    if (begin == end - 1){
      res.push_back(vector<int>(1, *begin));
      return res;
    }
    vector<vector<int> > tmp = permute1(begin + 1, end);
    for (int i = 0; i < tmp.size(); ++i){
      for (int j = 0; j <= tmp[i].size(); ++j){
        tmp[i].insert(tmp[i].begin() + j, *begin);
        res.push_back(tmp[i]);
        tmp[i].erase(tmp[i].begin() + j);
      }
    }
    return res;
  }

};

int main(){
  Solution s;
  int A[3] = {1, 2, 3};
  vector<int> v(A, A + 3);
  vector<vector<int> > res = s.permute(v);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < res[i].size(); ++j){
      cout << res[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
