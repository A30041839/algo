#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minCut(string s) {
    if (s.empty()) {
      return 0;
    }else {
      return minCut2(s);
    }
  }

  int minCut1(string s) {
    int n = s.size();
    vector<vector<int>> ispalind(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      ispalind[i][i] = 1;
    }
    for (int k = 2; k <= n; ++k) {
      for (int i = 0; i <= n - k; ++i) {
        if (k == 2) {
          ispalind[i][i + 1] = s[i] == s[i + 1];
        }else {
          ispalind[i][i + k - 1] = s[i] == s[i + k - 1] ? ispalind[i + 1][i + k - 2] : 0;
        }
      }
    }
    vector<int> dp(n, 0);
    for (int i = 1; i < n; ++i) {
      if (!ispalind[0][i]) {
        int tmp = INT_MAX;
        for (int j = i - 1; j >= 0; --j) {
          if (ispalind[j + 1][i]) {
            tmp = min(tmp, dp[j] + 1);
            if (tmp == 1) {
              break;
            }
          }
        }
        dp[i] = tmp;
      }
    }
    return dp[n - 1];
  }

  //space: O(n)
  int minCut2(string s) {
    //notice that we only want to judge whether s[i..j] is palindrome in each
    //iteration for a fixed ending position j, we can reduce the space complexity
    //to O(N)
    int n = s.size();
    vector<int> dp(n, 0);
    vector<int> mincut(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (i == j) {
          dp[i] = 1;
        }else if (j + 1 == i) {
          dp[j] = s[j] == s[i];
        }else {
          dp[j] = s[j] == s[i] ? dp[j + 1] : 0;
        }
      }
      int tmp = INT_MAX;
      for (int j = i; j >= 0; --j) {
        if (dp[j]) {
          if (j > 0) {
            tmp = min(tmp, mincut[j - 1] + 1);
          }else {
            tmp = 0;
          }
        }
      }
      mincut[i] = tmp;
    }
    return mincut[n - 1];
  }
};

int main() {
  Solution s;
  string str = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
  cout << s.minCut(str) << endl;
  return 0;

}
