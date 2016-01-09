class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int v : coins) {
        if (i >= v and dp[i - v] != -1) {
          if (dp[i] == -1) {
            dp[i] = dp[i - v] + 1;
          }else {
            dp[i] = min(dp[i], dp[i - v] + 1);
          }
        }
      }
    }
    return dp.back();
  }
};
