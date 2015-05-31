#include "leetcode.h"

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    return longestConsecutive1(nums);
  }

  //bidirectional detect
  int longestConsecutive1(vector<int> &nums) {
    unordered_set<int> mp;
    for (int x : nums){
      mp.insert(x);
    }
    int res = 0;
    for (int x : mp){
      int gt_cnt = 0, lt_cnt = 0;
      int val = x;
      while (mp.find(val + 1) != mp.end()){
        gt_cnt++;
        mp.erase(val + 1);
        val++;
      }
      val = x;
      while (mp.find(val - 1) != mp.end()){
        lt_cnt++;
        mp.erase(val - 1);
        val--;
      }
      res = max(res, gt_cnt + lt_cnt + 1);
    }
    return res;
  }

  int longestConsecutive2(vector<int> &nums) {
    unordered_set<int> st;
    for (int x : nums) {
      st.insert(x);
    }
    int res = 0;
    for (int x : st) {
      if (!st.count(x - 1)) {
        int val = x, cnt = 0;
        while (st.count(val)) {
          val++;
          cnt++;
        }
        res = max(res, cnt);
      }
    }
    return res;
  }

  //length of the consecutive sequence is stored in two ends
  int merge(unordered_map<int, int>& mp, int a, int b) {
    int left = a - mp[a] + 1;
    int right = b + mp[b] - 1;
    return mp[left] = mp[right] = right - left + 1;
  }

  int longestConsecutive3(vector<int> &nums) {
    unordered_map<int, int> mp;
    int res = 0;
    for (int x : nums) {
      if (mp[x] != 0) {
        continue;
      }
      mp[x] = 1;
      if (mp.count(x - 1)) {
        res = max(res, merge(mp, x - 1, x));
      }
      if (mp.count(x + 1)) {
        res = max(res, merge(mp, x, x + 1));
      }
      res = max(res, mp[x]);
    }
    return res;
  }

  int longestConsecutive4(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    vector<int> dp(n, 0);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      mp[nums[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
      if (dp[i] == 0) {
        computeLength(mp, nums[i], dp);
      }
      res = max(res, dp[i]);
    }
    return res;
  }

  int computeLength(unordered_map<int, int>& mp, int num, vector<int>& dp) {
    if (mp.find(num) == mp.end()) {
      return 0;
    }
    int index = mp[num];
    if (dp[index] > 0) {
      return dp[index];
    }else {
      return dp[index] = computeLength(mp, num - 1, dp) + 1;
    }
  }
};

int main(){
  Solution s;
  vector<int> nums = {100, 4, 200, 1, 3, 2, 101, 99, 104, 102, 103, 101};
  cout << s.longestConsecutive(nums) << endl;
  return 0;
}
