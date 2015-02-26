#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    return minPathSum1(grid);
  }

  int minPathSum1(vector<vector<int> >& grid){
    int k1 = grid.size();
    int k2 = grid[0].size();
    vector<vector<int> > dp(k1, vector<int>(k2, 0));
    dp[k1 - 1][k2 - 1] = grid[k1 - 1][k2 - 1];
    for (int i = k2 - 2; i >= 0; --i){
      dp[k1 - 1][i] = grid[k1 - 1][i] + dp[k1 - 1][i + 1];
    }
    for (int i = k1 - 2; i >= 0; --i){
      dp[i][k2 - 1] = grid[i][k2 - 1] + dp[i + 1][k2 - 1];
    }
    for (int i = k1 - 2; i >=0; --i){
      for (int j = k2 - 2; j >= 0; --j){
        dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return dp[0][0];
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
