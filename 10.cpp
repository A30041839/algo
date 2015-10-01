#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    return isMatch1(s, p);
  }

  bool isMatch1(string s, string p) {
    if (s.empty()) {
      return false;
    }
    int n = s.size();
    vector<bool> dp(n, false);

  }
};

int main(){
  Solution s;
  vector<string> strs = {"aaa", "aaabu", "aeffduggg", "aaa"};
  vector<string> patterns = {"a*a", "a*aabu", "c*aef*dug*gx", "ab*a*c*a"};
  for (int i = 0; i < strs.size(); ++i){
    if (s.isMatch(strs[i], patterns[i])){
      printf("%s matches %s\n", strs[i].c_str(), patterns[i].c_str());
    }else{
      printf("%s doesn't match %s\n", strs[i].c_str(), patterns[i].c_str());
    }
  }
  return 0;
}
