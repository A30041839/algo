#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(S.begin(), S.end());
    res.push_back(tmp);
    subsetsWithDup3(res, tmp, S, 0);
    return res;
  }

  void subsetsWithDup1(map<int, int>::iterator iter, map<int, int>::iterator iter_end,
    vector<int>& tmp, vector<vector<int>>& res) {
    if (iter == iter_end) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i <= iter->second; ++i) {
      tmp.insert(tmp.end(), i, iter->first);
      subsetsWithDup1(++iter, iter_end, tmp, res);
      --iter;
      tmp.erase(tmp.end() - i, tmp.end());
    }
  }

  vector<vector<int>> subsetsWithDup2(map<int, int>& mp) {
    vector<vector<int>> res = {{}};
    for (map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
      int n = res.size();
      for (int i = 0; i < n; ++i) {
        vector<int> tmp = res[i];
        for (int k = 0; k < iter->second; ++k) {
          tmp.push_back(iter->first);
          res.push_back(tmp);
        }
      }
    }
    return res;
  }

  void subsetsWithDup3(vector<vector<int>>& res, vector<int>& tmp, vector<int>& S,
    int start) {
    for (int i = start; i < S.size(); ++i) {
      if (i > start and S[i - 1] == S[i]) {
        continue;
      }
      tmp.push_back(S[i]);
      res.push_back(tmp);
      if (i < S.size() - 1) {
        subsetsWithDup3(res, tmp, S, i + 1);
      }
      tmp.pop_back();
    }
  }
};

int main(){
  Solution s;
  vector<int> v1 = {1,1};
  vector<vector<int> > res = s.subsetsWithDup(v1);
  for (auto& v2 : res){
    for (auto& i : v2){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
