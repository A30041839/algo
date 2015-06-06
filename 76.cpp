#include "leetcode.h"

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.empty() or t.empty()) {
      return "";
    }
    vector<int> actual(256, 0);
    vector<int> need(256, 0);
    int len_s = s.size(), len_t = t.size(), match = 0, min_len = INT_MAX;
    string res;
    for (int i = 0; i < len_t; ++i) {
      need[t[i]]++;
    }
    for (int p = 0, q = 0; q < len_s; ++q) {
      if (actual[s[q]] < need[s[q]]) {
        match++;
      }
      actual[s[q]]++;
      if (match == len_t) {
        while (actual[s[p]] > need[s[p]]) {
          actual[s[p]]--;
          p++;
        }
        if (q - p + 1 < min_len) {
          min_len = q - p + 1;
          res = s.substr(p, min_len);
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  string S = "ADOBECODEBANC";
  string T = "ABC";
  cout << s.minWindow(S, T) << endl;
  return 0;
}
