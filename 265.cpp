class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.empty() or costs[0].empty()) {
      return 0;
    }
    int k = costs[0].size();
    vector<int> dp(k, 0);
    int n = costs.size();
    int min1, min2;
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        dp = costs[0];
      }else {
        vector<int> tmp(k, 0);
        for (int j = 0; j < k; ++j) {
          tmp[j] = costs[i][j] + (dp[j] == min1 ? min2 : min1);
        }
        dp = tmp;
      }
      min1 = min2 = INT_MAX;
      for (int j = 0; j < k; ++j) {
        if (dp[j] < min1) {
          min2 = min1;
          min1 = dp[j];
        }else if (dp[j] < min2) {
          min2 = dp[j];
        }
      }
    }
    return min1;
  }
};
