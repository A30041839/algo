#include "leetcode.h"

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    return numTrees1(n);
  }

  //dp
  int numTrees1(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      //j left nodes, and i - j - 1 right nodes
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }
    return dp.back();
  }

  //recursive TLE!!
  int numTrees2(int n) {
    if (n == 0) {
      return 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += numTrees2(i) * numTrees2(n - i - 1);
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.numTrees(1) << endl;
  cout << s.numTrees(2) << endl;
  cout << s.numTrees(3) << endl;
  cout << s.numTrees(4) << endl;
  cout << s.numTrees(5) << endl;
  return 0;
}
