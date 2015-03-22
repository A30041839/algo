#include "leetcode.h"

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    return longestValidParentheses1(s);
  }

  int longestValidParentheses1(string s) {
    vector<int> v;
    int maxlen = 0, start = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        v.push_back(i);
      }else {
        if (v.empty()) {
          start = i + 1;
        }else {
          v.pop_back();
          maxlen = max(maxlen, v.empty() ? i - start + 1 : i - v.back());
        }
      }
    }
    return maxlen;
  }
};

int main(){
  Solution s;
  string s1 = "()(()";
  cout << s.longestValidParentheses(s1) << endl;
  return 0;
}
