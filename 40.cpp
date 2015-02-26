#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    vector<int> sol;
    return _combinationSum2(num, sol, 0, 0, target);
  }

  vector<vector<int> > _combinationSum2(vector<int> &num, vector<int>& sol,
                                        int begin, int cursum, int target) {
    if (cursum == target){
      return {{sol}};
    }
    vector<vector<int> > res;
    for (int i = begin; i < num.size() and (cursum + num[i]) <= target; ++i){
      if (sol.empty() and i > 0 and num[i] == num[i - 1]){
        continue;
      }
      sol.push_back(num[i]);
      for (auto& v : _combinationSum2(num, sol, i + 1, cursum + num[i], target)) {
       if (!duplicate(res, v)){
         res.push_back(v);
       }
      }
      sol.pop_back();
    }
    return res;
  }

  bool duplicate(vector<vector<int> >& v1, vector<int>& v2){
    for (int i = 0; i < v1.size(); ++i){
      if (v1[i].size() == v2.size()){
        int k;
        for (k = 0; k < v2.size(); ++k){
          if (v1[i][k] != v2[k]){
            break;
          }
        }
        if (k == v2.size()){
          return true;
        }
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  //vector<int> candidates = {2,2,2};
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
