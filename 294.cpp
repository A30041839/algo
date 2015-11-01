#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool canWin(string s) {
    return dfs(s, (int)s.size());
  }

  bool dfs(string s, int n) {
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == s[i + 1] and s[i] == '+') {
        s[i] = s[i + 1] = '-';
        bool win = !dfs(s, n);
        s[i] = s[i + 1] = '+';
        if (win) return true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  string str = "++++";
  if (s.canWin(str)) {
    cout << "yes";
  }
  return 0;
}
