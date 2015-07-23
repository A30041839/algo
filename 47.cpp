#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &nums) {
    return permuteUnique1(nums);
  }

  //why TLE?
  void dfs1(vector<vector<int>>& res, vector<int>&nums, int start) {
    if (start == nums.size() - 1) {
      res.push_back(nums);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      if (i != start and nums[i] == nums[start]) {
        continue;
      }
      swap(nums[start], nums[i]);
      dfs1(res, nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }

  vector<vector<int> > permuteUnique1(vector<int> &nums) {
    vector<vector<int>> res;
    dfs1(res, nums, 0);
    return res;
  }

  vector<vector<int> > permuteUnique2(vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    res.push_back(nums);
    while (nextPermutation(nums)) {
      res.push_back(nums);
    }
    return res;
  }

  bool nextPermutation(vector<int> &nums) {
    int pos1 = -1, pos2 = 0;
    int n = nums.size();
    for (int i = n - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        pos1 = i - 1;
        break;
      }
    }
    if (pos1 == -1) {
      return false;
    }
    for (int i = n - 1; i > 0; --i) {
      if (nums[i] > nums[pos1]) {
        pos2 = i;
        break;
      }
    }
    swap(nums[pos1], nums[pos2]);
    reverse(nums.begin() + pos1 + 1, nums.end());
    return true;
  }

  void dfs2(vector<vector<int>>& res, vector<int>& nums, vector<bool>& visit, vector<int>& sub) {
    if (sub.size() == nums.size()) {
      res.push_back(sub);
      return;
    }
    int last = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (visit[i]) {
        continue;
      }
      if (last != -1 and nums[last] == nums[i]) {
        continue;
      }
      sub.push_back(nums[i]);
      visit[i] = true;
      dfs2(res, nums, visit, sub);
      visit[i] = false;
      sub.pop_back();
      last = i;
    }
  }

  vector<vector<int> > permuteUnique3(vector<int> &nums) {
    vector<vector<int>> res;
    vector<bool> visit(nums.size(), false);
    vector<int> sub;
    //here must sort, otherwise will cause TLE, why?
    sort(nums.begin(), nums.end());
    dfs2(res, nums, visit, sub);
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {3,3,0,0,2,3,2};
  vector<vector<int> > res = s.permuteUnique(nums);
  for (auto& v : res){
    for (auto& i : v){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
