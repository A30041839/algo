#include "leetcode.h"

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    return numDecodings1(s);
  }

  int numDecodings1(string s){
    if (s.empty() or s[0] == '0') {
      return 0;
    }
    int n = s.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] == '1' or (s[i - 1] == '2' and s[i] >= '0' and s[i] <= '6')) {
        dp[i] += i > 1 ? dp[i - 2] : 1;
      }
      dp[i] += s[i] == '0' ? 0 : dp[i - 1];
    }
    return dp.back();
  }
};

int main(){
  Solution s;
  cout << s.numDecodings("12") << endl;
  cout << s.numDecodings("10") << endl;
  return 0;
}

