#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    return isIsomorphic1(s, t);
  }

  //notice this is a one to one mapping
  bool isIsomorphic1(string s, string t) {
    vector<int> s2t(256, 0), t2s(256, 0);
    int l = s.size();
    for (int i = 0; i < l; ++i) {
      if (s2t[s[i]] != 0) {
        if (s2t[s[i]] != t[i]) {
          return false;
        }
      }else {
        if (t2s[t[i]] != 0) {
          return false;
        }
        s2t[s[i]] = t[i];
        t2s[t[i]] = s[i];
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<string> arr1 = {"egg", "foo", "paper", "ab"};
  vector<string> arr2 = {"add", "bar", "title", "aa"};
  for (int i = 0; i < 3; ++i) {
    if (s.isIsomorphic(arr1[i], arr2[i])) {
      printf("%s and %s are isomorphic.\n", arr1[i].c_str(), arr2[i].c_str());
    }
  }
  return 0;
}
