#include "leetcode.h"

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if (!s.length()){
      return 0;
    }else{
      return numDecodings1(s);
    }
  }

  int numDecodings1(string s){
    vector<int> dp(s.length() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.length(); ++i){
      if (i > 1){
        if ((s[i - 2] == '1') or (s[i - 2] == '2' and s[i - 1] >= '0' and s[i - 1] <= '6')){
          dp[i] += dp[i - 2];
        }
      }
      if (s[i - 1] >= '1' and s[i - 1] <= '9'){
        dp[i] += dp[i - 1];
      }
    }
    return dp[s.length()];
  }
};

int main(){
  Solution s;
  cout << s.numDecodings("10") << endl;
  cout << s.numDecodings("0") << endl;
  return 0;
}

