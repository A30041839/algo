#include "leetcode.h"

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    return shortestPalindrome1(s);
  }

  //kmp
  string shortestPalindrome1(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    string t = s + "$" + r;
    vector<int> p(t.size(), 0);
    for (int i = 1; i < t.size(); ++i) {
      int j = p[i - 1];
      while (j > 0 and t[i] != t[j]) j = p[j - 1];
      p[i] = (j += t[i] == t[j]);
    }
    return r.substr(0, s.size() - p[t.size() - 1]) + s;
  }
};

int main() {
  Solution s;
  vector<string> v = {"aacecaaa", "abcd", "xaxx", "adcba", "cdcba", "ccba"};
  for (auto str : v) {
    cout << s.shortestPalindrome(str) << endl;
  }
  return 0;
}
