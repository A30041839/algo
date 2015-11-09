class Solution {
  vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
  vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};

  bool valid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
  }

  int countLiveCells(vector<vector<int>>& board, int x, int y, int m, int n) {
    int cnt = 0;
    for (int dir = 0; dir < 8; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (valid(nx, ny, m, n) and board[nx][ny] == 1) {
        cnt++;
      }
    }
    return cnt;
  }

  int countLiveCells2(vector<vector<int>>& board, int x, int y, int m, int n) {
    int cnt = 0;
    for (int dir = 0; dir < 8; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (valid(nx, ny, m, n) and (board[nx][ny] == 1 or board[nx][ny] == -1)) {
        cnt++;
      }
    }
    return cnt;
  }

public:
  void gameOfLife(vector<vector<int>>& board) {
    gameOfLife2(board);
  }

  void gameOfLife1(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> tmp = board;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int cnt = countLiveCells(board, i, j, m, n);
        if (board[i][j] == 1) {
          if (cnt < 2 or cnt > 3) {
            tmp[i][j] = 0;
          }
        }else if (cnt == 3) {
          tmp[i][j] = 1;
        }
      }
    }
    board = tmp;
  }

  //o(1) space
  void gameOfLife2(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int cnt = countLiveCells2(board, i, j, m, n);
        if (board[i][j] == 1) {
          if (cnt < 2 or cnt > 3) {
            board[i][j] = -1;
          }
        }else if (cnt == 3) {
          board[i][j] = 2;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 2) {
          board[i][j] = 1;
        }else if (board[i][j] == -1) {
          board[i][j] = 0;
        }
      }
    }
  }
};
