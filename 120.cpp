#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    return minimumTotal1(triangle);
  }

  int minimumTotal1(vector<vector<int> >& triangle) {
    int k = triangle.size();
    vector<vector<int> > dp(k, vector<int>(k, 0));
    dp[k - 1].assign(triangle[k - 1].begin(), triangle[k - 1].end());
    for (int i = k - 2; i >= 0; --i){
      for (int j = 0; j < i + 1; ++j){
        dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
      }
    }
    return dp[0][0];
  }
};

int main(){
  Solution s;
  vector<vector<int> > triangle;
  triangle.push_back({2});
  //triangle.push_back({3, 4});
  //triangle.push_back({6, 5, 7});
  //triangle.push_back({4, 1, 8, 3});
  cout << s.minimumTotal(triangle) << endl;
  return 0;
}
