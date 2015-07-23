#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    return levenshteinDist2(word1, word2);
  }

  //O(m*n) space
  int levenshteinDist1(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));//(m + 1)*(n + 1) matrix!
    //transform source to empty string by deleting chars
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i;
    }
    //transform empty string to target by inserting chars
    for (int i = 1; i <= n; ++i) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        int x = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;//substitution
        int y = dp[i - 1][j] + 1;//deletion
        int z = dp[i][j - 1] + 1;//insertion
        dp[i][j] = min(x, min(y, z));
      }
    }
    return dp[m][n];
  }

  //O(n) space
  int levenshteinDist2(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<int> cur(n + 1, 0), next(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cur[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
      next[0] = i;
      for (int j = 1; j <= n; ++j) {
        next[j] = min(word1[i - 1] == word2[j - 1] ? cur[j - 1] : cur[j - 1] + 1,
          min(cur[j] + 1, next[j - 1] + 1));
      }
      cur = next;
    }
    return cur.back();
  }
};

int main(){
  Solution s;
  string w1 = "sea";
  string w2 = "eat";
  cout << s.minDistance(w1, w2) << endl;
  return 0;
}
