#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int l1 = word1.length();
    int l2 = word2.length();
    if (!l1){
      return l2;
    }
    if (!l2){
      return l1;
    }
    vector<vector<int> > dp(l1, vector<int>(l2, 0));
    dp[0][0] = word1[0] == word2[0] ? 0 : 1;
    for (int i = 1; i < l2; ++i){
      dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i < l1; ++i){
      dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i < l1; ++i){
      for (int j = 1; j < l2; ++j){
        int a = word1[i] == word2[j] ? dp[i - 1][j - 1]: dp[i - 1][j - 1] + 1;
        int b = dp[i - 1][j] + 1;
        int c = dp[i][j - 1] + 1;
        dp[i][j] = min(a, min(b, c));
      }
    }
    return dp[l1 - 1][l2 - 1];
  }
};

int main(){
  Solution s;
  string w1 = "sea";
  string w2 = "eat";
  cout << s.minDistance(w1, w2) << endl;
  return 0;
}
