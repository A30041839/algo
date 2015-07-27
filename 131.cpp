#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<string> > partition(string s) {
    if (s.empty()) {
      return {};
    }else {
      return partition1(s);
    }
  }

  void dfs(vector<vector<int>>& dp, vector<vector<string>>& res,
    vector<string>& sub, string s, int beg) {
    if (beg == s.size()) {
      res.push_back(sub);
      return;
    }
    for (int end = beg; end < s.size(); ++end) {
      if (dp[beg][end]) {
        sub.push_back(s.substr(beg, end - beg + 1));
        dfs(dp, res, sub, s, end + 1);
        sub.pop_back();
      }
    }
  }

  vector<vector<string> > partition1(string s) {
    int n = s.size();
    //dp[i,j] = 1 if s[i...j] is a palindrome
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int k = 2; k <= n; ++k) {
      for (int i = 0; i <= n - k; ++i) {
        if (k == 2) {
          dp[i][i + 1] = s[i] == s[i + 1];
        }else {
          dp[i][i + k - 1] = s[i] == s[i + k - 1] ? dp[i + 1][i + k - 2] : 0;
        }
      }
    }
    vector<vector<string>> res;
    vector<string> sub;
    dfs(dp, res, sub, s, 0);
    return res;
  }
};

int main(){
  Solution s;
  string str("abaaba");
  vector<vector<string> > res = s.partition(str);
  for (auto& v : res){
    for (auto& tmp : v){
      cout << tmp << ",";
    }
    cout << endl;
  }
  return 0;
}
