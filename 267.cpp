#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> generatePalindromes(string s) {
    if (s.empty()) {
      return {};
    }
    unordered_map<char, int> mp;
    for (char c : s) {
      mp[c]++;
    }
    int cnt = 0;
    char mid;
    for (auto& p : mp) {
      if (p.second & 1) {
        cnt++;
        mid = p.first;
      }
    }
    if (cnt > 1) {
      return {};
    }
    vector<string> res;
    if (cnt == 1) {
      mp[mid]--;
      dfs(res, string(1, mid), mp, (s.size() - 1) / 2, 0);
    }else {
      dfs(res, "", mp, s.size() / 2, 0);
    }
    return res;
  }

  void dfs(vector<string>& res, string sub, unordered_map<char, int>& mp, int len, int cur) {
    if (cur == len) {
      int start = 0;
      if (sub.size() > len) {
        start = 1;
      }
      string tmp(sub.rbegin(), sub.rend() - start);
      res.push_back(tmp + sub);
      return;
    }
    for (auto& p : mp) {
      if (p.second > 0) {
        p.second -= 2;
        dfs(res, sub + p.first, mp, len, cur + 1);
        p.second += 2;
      }
    }
  }
};
