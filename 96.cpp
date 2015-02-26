#include "leetcode.h"

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    if (n <= 0){
      return 0;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i){
      for (int k = 0; k <= (i - 1) / 2; ++k){
        dp[i] += dp[k] * dp[i - k - 1] * 2;
      }
      dp[i] -= i & 1 ? dp[(i - 1) / 2] * dp[(i - 1) / 2] : 0;
    }
    return dp[n];
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
