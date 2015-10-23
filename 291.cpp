#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool wordPatternMatch(string pattern, string str) {
    unordered_map<char, string> p2s;
    unordered_set<string> s2p;
    return dfs(pattern, str, p2s, s2p);
  }

  bool dfs(string p, string s, unordered_map<char, string>& p2s, unordered_set<string> s2p) {
    if (p.empty() or s.empty()) {
      return p.empty() and s.empty();
    }
    if (p2s.count(p[0])) {
      string w = p2s[p[0]];
      if (s.substr(0, w.size()) != w) {
        return false;
      }
      return dfs(p.substr(1), s.substr(p2s[p[0]].size()), p2s, s2p);
    }else {
      int len = 0, cnt = 0;
      for (int i = 0; i < p.size(); ++i) {
        if (p2s.count(p[i])) {
          len += p2s[p[i]].size();
        }else if (p[i] != p[0]) {
          len += 1;
        }else {
          cnt++;
        }
      }
      len = (s.size() - len) / cnt;
      for (int i = 1; i <= len; i++) {
        string tmp = s.substr(0, i);
        if (!s2p.count(tmp)) {
          p2s[p[0]] = tmp;
          s2p.insert(tmp);
          if (dfs(p.substr(1), s.substr(tmp.size()), p2s, s2p)) {
            return true;
          }else {
            p2s.erase(p[0]);
            s2p.erase(tmp);
          }
        }
      }
    }
    return false;
  }
};
