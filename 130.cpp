#include "leetcode.h"

using namespace std;

class Solution {
private:
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};

public:
  void solve(vector<vector<char>>& board) {
    if (board.empty() or board[0].empty()) {
      return;
    }else {
      solve4(board);
    }
  }

  bool isValid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
  }

  bool onEdge(int x, int y, int m, int n) {
    return x == 0 or x == m - 1 or y == 0 or y == n - 1;
  }

  void flip(vector<vector<char>>& board, vector<pair<int, int>>& v) {
    for (auto& p : v) {
      board[p.first][p.second] = 'X';
    }
  }

  void bfs1(vector<vector<char>>& board, vector<vector<bool>>& visit, int curx,
    int cury, int m, int n) {
    queue<pair<int, int>> q;
    q.push({curx, cury});
    vector<pair<int, int>> v;
    visit[curx][cury] = true;
    bool f = true;
    while (!q.empty()) {
      curx = q.front().first;
      cury = q.front().second;
      v.push_back(q.front());
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if (isValid(nx, ny, m, n) and !visit[nx][ny] and board[nx][ny] == 'O') {
          visit[nx][ny] = true;
          if (onEdge(nx, ny, m, n)) {
            f = false;
          }
          q.push({nx, ny});
        }
      }
    }
    if (f) {
      flip(board, v);
    }
  }

  void solve1(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visit[i][j] and board[i][j] == 'O' and !onEdge(i, j, m, n)) {
          bfs1(board, visit, i, j, m, n);
        }
      }
    }
  }

  void dfs1(vector<vector<char>>& board, vector<vector<bool>>& visit,
    vector<pair<int, int>>& v, int curx, int cury, int m, int n, bool& flag) {
    visit[curx][cury] = true;
    v.push_back({curx, cury});
    if (onEdge(curx, cury, m, n)) {
      flag = false;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = dx[i] + curx;
      int ny = dy[i] + cury;
      if (isValid(nx, ny, m, n) and !visit[nx][ny] and board[nx][ny] == 'O') {
        dfs1(board, visit, v, nx, ny, m, n, flag);
      }
    }
  }

  void solve2(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    vector<pair<int, int>> v;
    bool f;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O' and !visit[i][j]) {
          v.clear();
          f = true;
          dfs1(board, visit, v, i, j, m, n, f);
          if (f) {
            flip(board, v);
          }
        }
      }
    }
  }

  void bfs2(vector<vector<char>>& board, queue<pair<int, int>>& q, int m, int n) {
    while (!q.empty()) {
      int curx = get<0>(q.front());
      int cury = get<1>(q.front());
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if (isValid(nx, ny, m, n) and board[nx][ny] == 'O') {
          board[nx][ny] = '$';
          q.push({nx, ny});
        }
      }
    }
  }

  //we expand from edge 'O' points which won't be flipped.
  //the remaining untouched 'O' points are flipped.
  void solve3(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        //record edge 'O' points
        if (onEdge(i, j, m, n) and board[i][j] == 'O') {
          board[i][j] = '$';
          q.push({i, j});
        }
      }
    }
    bfs2(board, q, m, n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '$') {
          board[i][j] = 'O';
        }else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs2(vector<vector<char>>& board, int curx, int cury, int m, int n) {
    board[curx][cury] = '$';
    for (int i = 0; i < 4; ++i) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (isValid(nx, ny, m, n) and board[nx][ny] == 'O') {
        dfs2(board, nx, ny, m, n);
      }
    }
  }

  //RTE
  void solve4(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (onEdge(i, j, m, n) and board[i][j] == 'O') {
          dfs2(board, i, j, m, n);
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '$') {
          board[i][j] = 'O';
        }else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};

int main(){
  Solution s;
  vector<vector<char> > board;
  //board.push_back({'O'});
  board.push_back({'X','X','X','O', 'X'});
  board.push_back({'X','O','X','O', 'X'});
  board.push_back({'X','O','X','O', 'X'});
  board.push_back({'X','X','X','X', 'X'});
  s.solve(board);
  for (auto& v : board){
    for (auto& x : v){
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
