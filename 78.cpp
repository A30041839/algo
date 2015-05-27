#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) {
      return {{}};
    }
    sort(nums.begin(), nums.end());
    return subsets3(nums);
  }

  vector<vector<int>> subsets1(vector<int>& nums, int dep) {
    if (dep == nums.size()) {
      return {{}};
    }
    auto res = subsets1(nums, dep + 1);
    int len = res.size();
    for (int i = 0; i < len; ++i) {
      vector<int> tmp = res[i];
      tmp.insert(tmp.begin(), nums[dep]);
      res.push_back(tmp);
    }
    return res;
  }

  void subsets2(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int dep) {
    if (dep == nums.size()) {
      res.push_back(tmp);
      return;
    }
    tmp.push_back(nums[dep]);
    subsets2(nums, res, tmp, dep + 1);
    tmp.pop_back();
    subsets2(nums, res, tmp, dep + 1);
  }

  //bit manipulation
  vector<vector<int>> subsets3(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    for (long i = 0; i < (1 << n); ++i) {
      vector<int> tmp;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          tmp.push_back(nums[j]);
        }
      }
      res.push_back(tmp);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {3, 2, 1};
  vector<vector<int>> res = s.subsets(nums);
  for (auto v : res) {
    for (auto x : v) {
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
