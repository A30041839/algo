#include "leetcode.h"

using namespace std;

class Solution {
public:
  string minWindow(string S, string T) {
    if (S.empty() or T.empty()) {
      return "";
    }
    vector<int> hash_s(256, 0);
    vector<int> hash_t(256, 0);
    int t_key_cnt = 0;
    for (int i = 0; i < T.size(); ++i) {
      hash_t[T[i]]++;
    }
    for (int i = 0; i < 256; ++i) {
      if (hash_t[i] > 0) {
        t_key_cnt++;
      }
    }
    int match = 0, min_len = INT_MAX;
    string res;
    for (int p = 0, q = 0; q < S.size(); ++q) {
      if (hash_t[S[q]] > 0) {
        if (++hash_s[S[q]] == hash_t[S[q]]) {
          match++;
        }
        if (match == t_key_cnt) {
          while (hash_t[S[p]] == 0 or hash_s[S[p]] > hash_t[S[p]]) {
            if (hash_s[S[p]] > 0) {
              hash_s[S[p]]--;
            }
            p++;
          }
          if (q - p + 1 < min_len) {
            min_len = q - p + 1;
            res = S.substr(p, min_len);
          }
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
