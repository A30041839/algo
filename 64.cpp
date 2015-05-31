#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.empty() or grid[0].empty()) {
      return 0;
    }else {
      return minPathSum2(grid);
    }
  }

  //O(mn) space
  int minPathSum1(vector<vector<int> >& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 and j == 0) {
          dp[0][0] = grid[0][0];
        }else if (i == 0) {
          dp[0][j] = dp[0][j - 1] + grid[0][j];
        }else if (j == 0) {
          dp[i][0] = dp[i - 1][0] + grid[i][0];
        }else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
      }
    }
    return dp[m - 1][n - 1];
  }

  //O(n) space
  int minPathSum2(vector<vector<int> >& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0) {
          j == 0 ? dp[0] = grid[0][0] : dp[j] = dp[j - 1] + grid[0][j];
        }else {
          j == 0 ? dp[0] += grid[i][0] : dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
      }
    }
    return dp[n - 1];
  }
};

int main(){
  Solution s;
  vector<vector<int> > grid;
  grid.push_back({1, 2, 5});
  grid.push_back({3, 2, 1});

  cout << s.minPathSum(grid) << endl;
  return 0;
}
