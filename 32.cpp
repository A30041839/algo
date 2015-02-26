#include "leetcode.h"

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (!s.length()){
      return 0;
    }
    return longestValidParentheses1(s);
  }

  int longestValidParentheses1(string s) {
    int max_len = 0, left = 0, cur_len = 0;
    vector<int> dp(s.length(), 0);
    for (int i = 0; i < s.length(); ++i){
      if (s[i] == '('){
        left++;
        cur_len = 0;
        dp[i] = i > 0 ? dp [i - 1]: 0;
      }else{
        if (left > 0){
          left--;
          cur_len += 2;
          if (i - cur_len > 0 and s[i - cur_len] == ')'){
            cur_len += dp[i - cur_len];
          }
        }
        dp[i] = cur_len;
      }
      max_len = max(max_len, dp[i]);
    }
    return max_len;
  }
};

int main(){
  Solution s;
  string s1 = ")()())()()(";
  cout << s.longestValidParentheses(s1) << endl;
  return 0;
}
