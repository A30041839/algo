#include "leetcode.h"
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
  }
};

int main() {
  Solution s;
  vector<string> strs = {"aa", "aa", "aaa", "aa", "aa", "ab", "aab"};
  vector<string> patterns = {"a", "aa", "aa", "*", "a*", "?*", "c*a*b"};
  for (int i = 0; i < strs.size(); ++i){
    if (s.isMatch(strs[i], patterns[i])){
      printf("%s matches %s\n", strs[i].c_str(), patterns[i].c_str());
    }else{
      printf("%s doesn't match %s\n", strs[i].c_str(), patterns[i].c_str());
    }
  }
  return 0;
}
