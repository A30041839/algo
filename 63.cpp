#include "leetcode.h"

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    if (obstacleGrid.empty() or obstacleGrid[0].empty()){
      return 0;
    }
    return uniquePathsWithObstacles2(obstacleGrid);
  }

private:
  //space: O(n^2)
  int uniquePathsWithObstacles1(vector<vector<int> >& grid){
    int m = grid.size();
    int n = grid[0].size();
    if (grid[0][0] == 1 or grid[m - 1][n - 1] == 1) {
      return 0;
    }
    vector<vector<int> > dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 and j == 0) {
          dp[0][0] = 1;
        }else if (grid[i][j] == 1) {
          dp[i][j] = 0;
        }else {
          dp[i][j] = dp[max(0, i - 1)][j] + dp[i][max(j - 1, 0)];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
  //space: O(n)
  int uniquePathsWithObstacles2(vector<vector<int> >& grid){
    int m = grid.size();
    int n = grid[0].size();
    if (grid[0][0] == 1 or grid[m - 1][n - 1] == 1) {
      return 0;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          dp[j] = 0;
        }else if (j > 0) {
          dp[j] += dp[j - 1];
        }
      }
    }
    return dp.back();
  }
};

int main(){
  Solution s;
  vector<vector<int> > grid;
  grid.push_back({0,0,0});
  grid.push_back({0,1,1});
  grid.push_back({0,0,0});
  cout << s.uniquePathsWithObstacles(grid) << endl;
  return 0;
}
