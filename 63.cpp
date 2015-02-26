#include "leetcode.h"

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    if (obstacleGrid.size() == 0){
      return 0;
    }
    return uniquePathsWithObstacles1(obstacleGrid);
  }

  int uniquePathsWithObstacles1(vector<vector<int> >& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > dp(m, vector<int>(n, 0));
    for (int i = n - 1; i >= 0 and grid[m - 1][i] != 1; --i){
      dp[m - 1][i] = 1;
    }
    for (int i = m - 1; i >= 0 and grid[i][n - 1] != 1; --i){
      dp[i][n - 1] = 1;
    }
    for (int i = m - 2; i >= 0; --i){
      for (int j = n - 2; j >= 0; --j){
        dp[i][j] = grid[i][j] == 1 ? 0 : dp[i + 1][j] + dp[i][j + 1];
      }
    }
    return dp[0][0];
  }
};

int main(){
  Solution s;
  vector<vector<int> > grid;
  grid.push_back({0,0,0});
  grid.push_back({1,1,1});
  grid.push_back({0,0,0});
  cout << s.uniquePathsWithObstacles(grid) << endl;
  return 0;
}
