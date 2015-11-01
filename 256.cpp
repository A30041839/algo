class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    if (costs.empty() or costs[0].empty()) {
      return 0;
    }
    vector<int> dp = costs[0];
    int n = costs.size();
    for (int i = 1; i < n; ++i) {
      vector<int> tmp(3, 0);
      tmp[0] = min(dp[1], dp[2]) + costs[i][0];
      tmp[1] = min(dp[0], dp[2]) + costs[i][1];
      tmp[2] = min(dp[0], dp[1]) + costs[i][2];
      dp = tmp;
    }
    return min(dp[0], min(dp[1], dp[2]));
  }
};
