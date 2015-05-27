#include "leetcode.h"

using namespace std;

//visit the matrix element one by one, change direction when the next position is
//invalid
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    if (matrix.empty() or matrix[0].empty()) {
      return res;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> dirx = {0, 1, 0, -1};
    vector<int> diry = {1, 0, -1, 0};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int dir = 0, curx = 0, cury = 0;
    for (int i = 0; i < m * n; ++i) {
      visited[curx][cury] = true;
      res.push_back(matrix[curx][cury]);
      int next_x = curx + dirx[dir];
      int next_y = cury + diry[dir];
      if (next_x < 0 or next_x >= m or next_y < 0 or next_y >= n
        or visited[next_x][next_y] == true) {
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
  vector<vector<int> > matrix;
  matrix.push_back({1,2,3});
  matrix.push_back({4,5,6});
  vector<int> res = s.spiralOrder(matrix);
  for (int i : res){
    cout << i << ",";
  }
  cout << endl;
  return 0;
}
