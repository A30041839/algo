#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool canWin(string s) {
    if (s.empty()) {
      return true;
    }
    int n = s.size();
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[i - 1] and s[i] == '+') {
        s[i] = s[i - 1] = '-';
        bool f = true;
        dfs(s, f, n, 0);
        s[i] = s[i - 1] = '+';
        if (f) {
          return true;
        }
      }
    }
    return false;
  }

  void dfs(string s, bool& f, int n, int dep) {
    bool win = false;
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[i - 1] and s[i] == '+') {
        win = true;
        s[i] = s[i - 1] = '-';
        dfs(s, f, n, dep + 1);
        s[i] = s[i - 1] = '+';
      }
    }
    if (!win) {
      if (dep & 0) {
        f = false;
      }
    }
  }
};

int main() {
  Solution s;
  string str = "+++++++++++++++++++++";
  if (s.canWin(str)) {
    cout << "yes";
  }
  return 0;
}
