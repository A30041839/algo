#include "leetcode.h"
using namespace std;

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    if (s.size() < t.size()) swap(s, t);
    int ls = (int)s.size(), lt = (int)t.size();
    int i = 0, j = 1;
    while (i < ls and i < lt) {
      if (s[i] == t[i]) i++; else break;
    }
    while (j <= ls and j <= lt) {
      if (s[ls - j] == t[lt - j]) j++; else break;
    }
    return i + j == ls;
  }
};

int main(){
  Solution s;
  string s1 = "ab";
  string s2 = "acb";
  if (s.isOneEditDistance(s1, s2)) {
    cout << "yes" << endl;
  }
  return 0;
}
