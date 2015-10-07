#include "leetcode.h"

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    if (n < 1) {
      return 0;
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 1;
    for (int i = 2; i <= n; ++i) {
      int k = sqrt(i);
      if (k * k == i) {
        dp[i - 1] = 1;
      }else {
        for (int j = 1; j * j < i; ++j) {
          dp[i - 1] = min(dp[i - 1], dp[j * j - 1] + dp[i - j * j - 1]);
        }
      }
    }
    return dp[n - 1];
  }
};

int main() {
  Solution s;
  vector<int> v = {12, 13, 9975};
  for (int x : v) {
    cout << s.numSquares(x) << endl;
  }
}
