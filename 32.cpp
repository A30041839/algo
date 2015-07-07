#include "leetcode.h"

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    return longestValidParentheses1(s);
  }

  //maintain a stack to record the position of '('.
  //use a start pointer to record the real start position of
  //a substring
  int longestValidParentheses1(string s) {
    int n = s.size(), res = 0, start = 0;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        v.push_back(i);
      }else {
        if (v.empty()) {
          //last sequence becomes invalid
          start = i + 1;
        }else {
          v.pop_back();
          res = max(res, v.empty() ? i - start + 1 : i - v.back());
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  string s1 = "()(()";
  cout << s.longestValidParentheses(s1) << endl;
  return 0;
}
