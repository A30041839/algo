#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.empty() or triangle[0].empty()) {
      return 0;
    }else {
      return minimumTotal2(triangle);
    }
  }

  int minimumTotal1(vector<vector<int> >& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1].assign(triangle[n - 1].begin(), triangle[n - 1].end());
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
      }
    }
    return dp[0][0];
  }

  int minimumTotal2(vector<vector<int> >& triangle) {
    int n = triangle.size();
    vector<int> dp = triangle[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
      }
    }
    return dp[0];
  }
};

int main(){
  Solution s;
  vector<vector<int> > triangle;
  triangle.push_back({2});
  triangle.push_back({3, 4});
  triangle.push_back({6, 5, 7});
  triangle.push_back({4, 1, 8, 3});
  cout << s.minimumTotal(triangle) << endl;
  return 0;
}
