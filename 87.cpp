#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.empty()) {
      return false;
    }
    int n = s1.size();
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n, false)));
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        for (int j = 0; j <= n - len; ++j) {
          if (len == 1) {
            dp[i][j][0] = s1[i] == s2[j];
          }else {
            for (int k = 1; k < len; ++k) {
              if ((dp[i][j][k - 1] and dp[i + k][j + k][len - k - 1]) or
                   (dp[i][j + len - k][k - 1] and dp[i + k][j][len - k - 1])) {
                dp[i][j][len - 1] = true;
                break;
              }
            }
          }
        }
      }
    }
    return dp[0][0][n - 1];
  }
};

int main() {
  Solution s;
  if (s.isScramble("rgtae", "great")) {
    cout << "yes" << endl;
  }
}
