#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n){
    if (n == 0){
      return {0};
    }
    vector<vector<int> > res = gen_grayCode(n);
    vector<int> result;
    for (int i = 0; i < res.size(); ++i){
      int k = 0;
      for (int j = 0; j < res[i].size(); ++j){
        k <<= 1;
        k += res[i][j];
      }
      result.push_back(k);
    }
    return result;
  }

  vector<vector<int> > gen_grayCode(int n){
    if (n == 1){
      return {{0}, {1}};
    }
    vector<vector<int> > res;
    auto v = gen_grayCode(n - 1);
    for (int i = 0; i < v.size(); ++i){
      vector<int> tmp(v[i].begin(), v[i].end());
      tmp.insert(tmp.begin(), 0);
      res.insert(res.begin() + i, tmp);
    }
    for (int i = v.size() - 1; i >= 0; --i){
      vector<int> tmp(v[i].begin(), v[i].end());
      tmp.insert(tmp.begin(), 1);
      res.push_back(tmp);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> res = s.grayCode(1);
  for (int a : res){
    cout << a << ",";
  }
  cout << endl;
  return 0;
}
