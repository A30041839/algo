#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool canPermutePalindrome(string s) {
    if (s.empty()) {
      return true;
    }
    vector<int> mp(256, 0);
    for (int i = 0; i < s.size(); ++i) {
      mp[s[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < 256; ++i) {
      if (mp[i] & 1) {
        cnt++;
      }
    }
    return cnt <= 1;
  }
};
