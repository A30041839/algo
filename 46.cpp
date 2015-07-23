#include "leetcode.h"

using namespace std;

class Solution {
private:
  int fact(int x) {
    if (x == 0) {
      return 1;
    }else {
      return x * fact(x - 1);
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }else {
      return permute5(nums);
    }
  }

  void dfs1(vector<vector<int>>& res, vector<int>& nums, int beg) {
    if (beg == nums.size()) {
      res.push_back(nums);
      return;
    }
    for (int i = beg; i < nums.size(); ++i) {
      swap(nums[i], nums[beg]);
      dfs1(res, nums, beg + 1);
      swap(nums[i], nums[beg]);
    }
  }

  vector<vector<int>> permute1(vector<int>& nums) {
    vector<vector<int>> res;
    dfs1(res, nums, 0);
    return res;
  }

  vector<vector<int>> permute2(vector<int>& nums) {
    int n = nums.size();
    int f = fact(n);
    vector<vector<int>> res;
    for (int i = 0; i < f; ++i) {
      int _f = f, _i = i;
      vector<int> tmp;
      vector<int> _nums = nums;
      for (int j = 0; j < n; ++j) {
        _f /= (n - j);
        tmp.push_back(_nums[_i / _f]);
        _nums.erase(_nums.begin() + _i / _f);
        _i %= _f;
      }
      res.push_back(tmp);
    }
    return res;
  }

  void dfs2(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp) {
    if (nums.empty()) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      int m = nums[i];
      tmp.push_back(m);
      nums.erase(nums.begin() + i);
      dfs2(res, nums, tmp);
      nums.insert(nums.begin() + i, m);
      tmp.pop_back();
    }
  }

  vector<vector<int>> permute3(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs2(res, nums, tmp);
    return res;
  }

  vector<vector<int>> permute4(vector<int>& nums) {
    if (nums.empty()) {
      return {{}};
    }
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      int m = nums[i];
      nums.erase(nums.begin() + i);
      auto tmp = permute4(nums);
      nums.insert(nums.begin() + i, m);
      for (auto& v : tmp) {
        v.insert(v.begin(), m);
        res.push_back(v);
      }
    }
    return res;
  }

  vector<vector<int>> permute5(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    do {
      res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int> > res = s.permute(nums);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < res[i].size(); ++j){
      cout << res[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
