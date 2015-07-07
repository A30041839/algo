#include "leetcode.h"

using namespace std;

class Solution {
private:
  vector<int> dx = {1,-1,0,0};
  vector<int> dy = {0,0,-1,1};

public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() or grid[0].empty()) {
      return 0;
    }else {
      return numIslands1(grid);
    }
  }

  bool isValid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
  }

  void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q, int m, int n) {
    while (!q.empty()) {
      int curx = get<0>(q.front());
      int cury = get<1>(q.front());
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if (isValid(nx, ny, m, n) and grid[nx][ny] == '1') {
          grid[nx][ny] = '$';//! this will avoid enqueue the same element twice
          q.push({nx, ny});
        }
      }
    }
  }

  int numIslands1(vector<vector<char>>& grid) {
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          grid[i][j] = '$';
          q.push({i, j});
          bfs(grid, q, m, n);
          res++;
        }
      }
    }
    return res;
  }

  void dfs(vector<vector<char>>& grid, int curx, int cury, int m, int n) {
    grid[curx][cury] = '$';
    for (int i = 0; i < 4; ++i) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (isValid(nx, ny, m, n) and grid[nx][ny] == '1') {
        dfs(grid, nx, ny, m, n);
      }
    }
  }

  int numIslands2(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j, m, n);
          res++;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<char>> grid;
  grid.push_back({'1','1','1','1','0'});
  grid.push_back({'1','1','0','0','0'});
  grid.push_back({'1','1','0','1','0'});
  grid.push_back({'0','0','0','0','1'});
  cout << s.numIslands(grid) << endl;
  return 0;
}
