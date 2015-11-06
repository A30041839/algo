#include "leetcode.h"
using namespace std;

class Solution {
  bool valid(string str) {
    int l = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == '(') l++;
      if (str[i] == ')') {
        if (l == 0) {
          return false;
        }
        l--;
      }
    }
    return l == 0;
  }

  void dfs(vector<string>& res, string s, int remove) {
    if (remove == 0) {
      if (valid(s)) {
        res.push_back(s);
      }
      return;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (i > 0 and s[i - 1] == s[i]) continue;
    }
  }

public:
  vector<string> removeInvalidParentheses(string s) {
    if (valid(s)) return {s};
    vector<string> res;
    for (int k = 1; k <= s.size(); ++k) {
      dfs(res, s, k);
      if (!res.empty()) return res;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> test = {"()())()", "(a)())()", ")(", ")()(" ")()m)(((()((()(((("};
  for (auto str : test) {
    vector<string> res = s.removeInvalidParentheses(str);
    print_vec(res);
  }
  return 0;
}
