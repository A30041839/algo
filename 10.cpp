#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    return isMatch1(s, p);
  }

  bool isMatch1(string s, string p) {
    int slen = s.size(), plen = p.size();
    vector<bool> dp(slen + 1, false);
    dp[0] = true;
    for (int i = 0; i < plen; ++i) {
      if (i < plen - 1 and p[i + 1] == '*') {
        continue;
      }
      vector<bool> tmp(slen + 1, false);
      if (p[i] == '*') {
        tmp = dp;
        for (int j = 0; j < slen + 1; ++j) {
          if (dp[j] == false) continue;
          for (int k = j; k < slen; ++k) {
            if (p[i - 1] != '.') {
              if (s[k] != p[i - 1]) {
                break;
              }
            }
            tmp[k + 1] = true;
          }
        }
      }else {
        for (int j = 0; j < slen + 1; ++j) {
          if (dp[j] == false) continue;
          if (j < slen) {
            if (p[i] == '.' or s[j] == p[i]) {
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

int main(){
  Solution s;
  vector<string> strs = {"aaa", "aaabu", "aeffduggg", "aaa", "ccbbabbbabababa"};
  vector<string> patterns = {"a*a", "a*aabu", "c*aef*dug*gx", "a.a", ".*.ba*c*c*aab.a*b*"};
  for (int i = 0; i < strs.size(); ++i){
    if (s.isMatch(strs[i], patterns[i])){
      printf("%s matches %s\n", strs[i].c_str(), patterns[i].c_str());
    }else{
      printf("%s doesn't match %s\n", strs[i].c_str(), patterns[i].c_str());
    }
  }
  return 0;
}
