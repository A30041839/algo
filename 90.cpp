#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    unordered_map<int, int> mp;
    vector<vector<int> > res = {{}};
    vector<int> uniqS;
    for (int i = 0; i < S.size(); ++i){
      mp[S[i]]++;
      if (uniqS.empty() or uniqS.back() != S[i]){
        uniqS.push_back(S[i]);
      }
    }
    _subsetsWithDup(uniqS, mp, res, 0);
    return res;
  }

  vector<vector<int> > _subsetsWithDup(vector<int>& v, unordered_map<int, int>& mp,
                                       vector<vector<int> >& res, int i){
    if (i == v.size()){
      return {{}};
    }
    vector<vector<int> > res1;
    for (auto& v1 : _subsetsWithDup(v, mp, res, i + 1)){
      res1.push_back(v1);
      vector<int> v2 = v1;
      v2.insert(v2.begin(), v[i]);
      res1.push_back(v2);
      vector<int> tmp;
      _expand(0, v2, mp, res, tmp);
    }
    return res1;
  }

  void _expand(int i, vector<int>& v, unordered_map<int, int>& mp,
               vector<vector<int> >& res, vector<int>& tmp){
    if (i == v.size()){
      res.push_back(tmp);
      return;
    }
    for (int k = 1; k <= mp[v[i]]; ++k){
      tmp.insert(tmp.end(), k, v[i]);
      _expand(i + 1, v, mp, res, tmp);
      tmp.erase(tmp.end() - k, tmp.end());
    }
  }
};

int main(){
  Solution s;
  vector<int> v1 = {1, 1, 2, 2};
  vector<vector<int> > res = s.subsetsWithDup(v1);
  for (auto& v2 : res){
    for (auto& i : v2){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
