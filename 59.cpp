#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    if (n < 1) {
      return {};
    }
    vector<vector<int> > res(n, vector<int>(n, 0));
    vector<int> dirx = {0, 1, 0, -1};
    vector<int> diry = {1, 0, -1, 0};
    int dir = 0, curx = 0, cury = 0;
    for (int i = 0; i < n * n; ++i) {
      res[curx][cury] = i + 1;
      int nx = curx + dirx[dir];
      int ny = cury + diry[dir];
      if (nx < 0 or nx >= n or ny < 0 or ny >= n or res[nx][ny] != 0) {
        dir = (dir + 1) % 4;
      }
      curx += dirx[dir];
      cury += diry[dir];
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<vector<int> > res = s.generateMatrix(3);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < res.size(); ++j){
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  /*
   * 1 2 3
   * 8 9 4
   * 7 6 5
   */
  return 0;
}
