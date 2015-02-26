#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    return isMatch1(s, p);
  }

  bool isMatch1(const char* s, const char* p){
  }
};

int main(){
  Solution s;
  vector<string> strs = {"aaa", "aaabu", "aeffduggg", "aaa"};
  vector<string> patterns = {"a*a", "a*aabu", "c*aef*dug*gx", "ab*a*c*a"};
 
  for (int i = 0; i < strs.size(); ++i){
    if (s.isMatch(strs[i].c_str(), patterns[i].c_str())){
      printf("%s matches %s\n", strs[i].c_str(), patterns[i].c_str());
    }else{
      printf("%s doesn't match %s\n", strs[i].c_str(), patterns[i].c_str());
    }
  }
  return 0;
}
