class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    return lengthOfLIS2(nums);
  }

  int lengthOfLIS1(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      res = max(res, dp[i]);
    }
    return res;
  }

  //binary search
  int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (res.empty() or res.back() < nums[i]) {
        res.push_back(nums[i]);
      }else {
        int l = 0, h = res.size() - 1;
        while (l < h) {
          int mid = l + (h - l) / 2;
          if (res[mid] < nums[i]) {
            l = mid + 1;
          }else {
            h = mid;
          }
        }
        res[l] = nums[i];
      }
    }
    return (int)res.size();
  }
};
