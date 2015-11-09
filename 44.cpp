#include "leetcode.h"
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int slen = s.size(), plen = p.size();
    vector<bool> dp(slen + 1, false);
    dp[0] = true;
    for (int i = 0; i < plen; ++i) {
      vector<bool> tmp(slen + 1, false);
      if (p[i] == '*') {
        //matches any sequence
        int j = 0;
        for (; j <= slen; ++j) {
          if (dp[j]) break;
        }
        while (j <= slen) {
          tmp[j++] = true;
        }
      }else {
        for (int j = 0; j <= slen; ++j) {
          if (dp[j] and j < slen) {
            if (p[i] == '?' or p[i] == s[j]) {
              tmp[j + 1] = true;
            }
          }
        }
      }
      dp = tmp;
    }
    return dp.back();
  }
};

int main() {
  Solution s;
  vector<string> strs = {"a", "aa", "aaa", "aa", "aa", "ab", "aab"};
  vector<string> patterns = {"aa", "aa", "aa", "*", "a*", "?*", "c*a*b"};
  for (int i = 0; i < strs.size(); ++i){
    if (s.isMatch(strs[i], patterns[i])){
      printf("%s matches %s\n", strs[i].c_str(), patterns[i].c_str());
    }else{
      printf("%s doesn't match %s\n", strs[i].c_str(), patterns[i].c_str());
    }
  }
  return 0;
}
