#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    return _combinationSum2b(candidates, target);
  }

  vector<vector<int>> _combinationSum2a(vector<int>& candidates, int target) {
    vector<int> sol;
    vector<vector<int>> res;
    map<int, int> mp;
    for (int x : candidates) {
      mp[x]++;
    }
    dfs1(mp.begin(), mp.end(), sol, res, target);
    return res;
  }

  void dfs1(map<int, int>::iterator iter, map<int, int>::iterator end,
    vector<int>& sol, vector<vector<int>>& res, int remain) {
    if (remain == 0) {
      res.push_back(sol);
      return;
    }
    if (iter != end) {
      for (int i = 0; i <= iter->second and i * iter->first <= remain; ++i) {
        int tmp = remain - i * iter->first;
        sol.insert(sol.end(), i, iter->first);
        dfs1(++iter, end, sol, res, tmp);
        --iter;
        sol.erase(sol.end() - i, sol.end());
      }
    }
  }

  vector<vector<int>> _combinationSum2b(vector<int>& candidates, int target) {
    vector<int> sol;
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    dfs2(candidates, sol, res, 0, target);
    return res;
  }

  void dfs2(vector<int>& candidates, vector<int>& sol, vector<vector<int>>& res,
    int start, int remain) {
    if (remain == 0) {
      res.push_back(sol);
      return;
    }
    for (int i = start; i < candidates.size() and candidates[i] <= remain; ++i) {
      if (i > start and candidates[i] == candidates[i - 1]) {
        continue;
      }
      sol.push_back(candidates[i]);
      dfs2(candidates, sol, res, i + 1, remain - candidates[i]);
      sol.pop_back();
    }
  }
 };

int main(){
  Solution s;
  vector<int> candidates = {10,1,2,7,6,1,5};
  vector<vector<int> > res = s.combinationSum2(candidates, 8);
  for (auto& v : res){
    for (auto& i : v){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
