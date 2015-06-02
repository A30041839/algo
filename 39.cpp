#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> sol;
    vector<vector<int>> res;
    combinationSum3(candidates, sol, res, 0, target);
    return res;
  }

  vector<vector<int> > combinationSum1(vector<int>& candidates, vector<int>& sol,
                                       int begin, int cursum, int target){
    if (cursum == target){
      return {{sol}};
    }
    vector<vector<int> > res;
    for (int i = begin; i < candidates.size() and (cursum + candidates[i] <= target); ++i){
      sol.push_back(candidates[i]);
      vector<vector<int> > tmp = combinationSum1(candidates, sol, i, cursum + candidates[i], target);
      for (auto& v : tmp){
        res.push_back(v);
      }
      sol.pop_back();
    }
    return res;
  }

  void combinationSum2(vector<int>& candidates, vector<int>& sol, vector<vector<int>>& res,
    int start, int sum, int target) {
    if (sum == target) {
      res.push_back(sol);
      return;
    }
    for (int i = 0; start < candidates.size() and i <= (target - sum) / candidates[start]; ++i) {
      sol.insert(sol.end(), i, candidates[start]);
      combinationSum2(candidates, sol, res, start + 1, sum + i * candidates[start], target);
      sol.erase(sol.end() - i, sol.end());
    }
  }

  void combinationSum3(vector<int>& candidates, vector<int>& sol, vector<vector<int>>& res,
    int start, int remain) {
    if (remain == 0) {
      res.push_back(sol);
      return;
    }
    for (int i = start; i < candidates.size() and candidates[i] <= remain; ++i) {
      sol.push_back(candidates[i]);
      combinationSum3(candidates, sol, res, i, remain - candidates[i]);
      sol.pop_back();
    }
  }
};

int main(){
  Solution s;
  vector<int> candidates = {1,2,3,6,7};
  vector<vector<int> > res = s.combinationSum(candidates, 6);
  for (auto& v : res){
    for (auto& i : v){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
