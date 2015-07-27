#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    return wordBreak1(s, wordDict);
  }

  vector<string> dfs1(string s, vector<vector<int>>& dp) {
    if (s.empty()) {
      return {""};
    }
    vector<string> res;
    for (auto& k : dp[s.size() - 1]) {
      auto v = dfs1(s.substr(0, k), dp);
      string cur = s.substr(k);
      for (auto& str : v) {
        if (str.empty()) {
          res.push_back(cur);
        }else {
          res.push_back(str + " " + cur);
        }
      }
    }
    return res;
  }

  vector<string> wordBreak1(string s, unordered_set<string>& wordDict) {
    //use a matrix to store every possible segment point for each substring
    if (s.empty() or wordDict.empty()) {
      return {};
    }
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>());
    for (int i = 0; i < n; ++i) {
      if (wordDict.count(s.substr(0, i + 1))) {
        dp[i].push_back(0);
      }
      for (int k = 0; k < i; ++k) {
        if (!dp[k].empty() and wordDict.count(s.substr(k + 1, i - k))) {
          dp[i].push_back(k + 1);
        }
      }
    }
    if (dp.back().empty()) {
      return {};
    }
    return dfs1(s, dp);
  }

  vector<string> dfs2(string s, unordered_set<string>& wordDict, vector<bool>& p) {
    if (s.empty()) {
      return {""};
    }
    vector<string> res;
    for (int i = s.size() - 1; i >= 0; --i) {
      string cur = s.substr(i);
      if (wordDict.count(cur)) {
        if (i > 0 and !p[i - 1]) {
          continue;
        }
        auto v = dfs2(s.substr(0, i), wordDict, p);
        for (auto& str : v) {
          if (str.empty()) {
            res.push_back(cur);
          }else {
            res.push_back(str + " " + cur);
          }
        }
      }
    }
    return res;
  }

  vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
    if (s.empty() or wordDict.empty()) {
      return {};
    }
    int n = s.size();
    vector<bool> p(n, false);
    for (int i = 0; i < n; ++i) {
      if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
        p[i] = true;
      }else {
        for (int k = i - 1; k >= 0; --k) {
          if (p[k] == true and wordDict.find(s.substr(k + 1, i - k)) != wordDict.end()) {
            p[i] = true;
            break;
          }
        }
      }
    }
    if (!p.back()) {
      return {};
    }
    return dfs2(s, wordDict, p);
  }
};

int main(){
  Solution s;
  //unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
  //string str = "catsanddog";
  string str = "aaaaaaa";
  unordered_set<string> dict = {"aaaa","aa","a"};
  //string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
  //unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  vector<string> res = s.wordBreak(str, dict);
  for (string& sen : res) {
    cout << sen << endl;
  }
  return 0;
}
