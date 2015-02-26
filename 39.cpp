#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> sol;
    return combinationSum1(candidates, sol, 0, 0, target);
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
};

int main(){
  Solution s;
  vector<int> candidates = {1,2,3,6,7};
  vector<vector<int> > res = s.combinationSum(candidates, 10);
  for (auto& v : res){
    for (auto& i : v){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
