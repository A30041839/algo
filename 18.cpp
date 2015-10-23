#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    return fourSum2(nums, target);
  }

  //O(n^3) time
  vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    int n = nums.size();
    if (n < 4) {
      return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i <= n - 4; ++i) {
      if (i > 0 and nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j <= n - 3; ++j) {
        if (j > i + 1 and nums[j] == nums[j - 1]) {
          continue;
        }
        int start = j + 1, end = n - 1;
        while (start < end) {
          int sum = nums[i] + nums[j] + nums[start] + nums[end];
          if (sum == target) {
            res.push_back({nums[i], nums[j], nums[start++], nums[end--]});
            while (start < end and nums[start] == nums[start - 1]) {
              start++;
            }
            while (start < end and nums[end] == nums[end + 1]) {
              end--;
            }
          }else if (sum < target) {
            start++;
          }else {
            end--;
          }
        }
      }
    }
    return res;
  }

  vector<vector<int>> fourSum2(vector<int>& nums, int target) {
    vector<vector<int>> res;
    unordered_map<int, vector<pair<int, int>>> mp;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        mp[nums[i] + nums[j]].push_back(make_pair(i, j));
      }
    }
    for (auto& kvp : mp) {
      auto iter = mp.find(target - kvp.first);
      if (iter != mp.end() and kvp.first <= iter->first) {
        for (auto& p1 : kvp.second) {
          for (auto& p2 : iter->second) {
            if (check(p1, p2)) {
              vector<int> tmp = {nums[p1.first], nums[p1.second], nums[p2.first], nums[p2.second]};
              sort(tmp.begin(), tmp.end());
              if (find(res.begin(), res.end(), tmp) == res.end()) {
                res.push_back(tmp);
              }
            }
          }
        }
      }
    }
    return res;
  }

  bool check(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first or p1.first == p2.second or p1.second == p2.first
      or p1.second == p2.second) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1,0,-1,0,-2,2};
  auto res = s.fourSum(nums, 0);
  for (auto v : res) {
    for (auto x : v) {
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
