#include "leetcode.h"

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m < 1 or n < 1) {
      return 0;
    }else {
      return uniquePaths3(m, n);
    }
  }

private:
  //time complexity:O(n^2)
  //space complexity: O(n^2)
  int uniquePaths1(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = m - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
    return dp[0][0];
  }

  //time complexity:O(n^2)
  //space complexity: O(n)
  int uniquePaths2(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 0; i < m - 1; ++i) {
      for (int j = n - 2; j >= 0; --j) {
        dp[j] += dp[j + 1];
      }
    }
    return dp[0];
  }

  int uniquePaths3(int m, int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] += dp[j - 1];
      }
    }
    return dp.back();
  }

  //math: C(n + m - 2, m - 1)
  //for integer a and integer experession b:
  //a *= b is not always equivalent to a = a * b
  int uniquePaths4(int m, int n) {
    long long res = 1;
    if (m < n) {
      swap(m, n);
    }
    for (int i = 1; i < n; ++i) {
      res = res * (n + m - 1 - i) / i;
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.uniquePaths(3, 7) << endl;
  return 0;
}
