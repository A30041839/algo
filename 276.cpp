#include "leetcode.h"

using namespace std;

class Solution {
public:
  int numWays(int n, int k) {
    if (k == 0 or n == 0) {
      return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = k;
    for (int i = 1; i < n; ++i) {
      dp[i] = dp[i - 1] * (k - 1);
      dp[i] += i >= 2 ? dp[i - 2] * (k - 1) : k;
    }
    return dp.back();
  }
};
