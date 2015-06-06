#include "leetcode.h"

using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char> > &board) {
    if (board.empty() or board[0].empty()) {
      return;
    }
    init(board);
    solveSudoku1(board, empty, 0);
  }

private:
  void init(vector<vector<char>>& board) {
    row.assign(N, 0);
    col.assign(N, 0);
    block.assign(N, 0);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] != '.') {
          int mask = 1 << (board[i][j] - '1');
          row[i] |= mask;
          col[j] |= mask;
          block[i / 3 * 3 + j / 3] |= mask;
        }else {
          empty.push_back(make_pair(i, j));
        }
      }
    }
  }

  bool solveSudoku1(vector<vector<char>>& board, vector<pair<int, int>>& empty,
    int pos) {
    if (pos == empty.size()) {
      return true;
    }
    int curx = empty[pos].first, cury = empty[pos].second;
    for (int i = 1; i <= N; ++i) {
      if (check(curx, cury, i)) {
        board[curx][cury] = '0' + i;
        if (solveSudoku1(board, empty, pos + 1)){
          return true;
        }else {
          board[curx][cury] = '.';
          clear(curx, cury, i);
        }
      }
    }
    return false;
  }

  bool check(int x, int y, int num) {
    int mask = 1 << (num - 1);
    if (row[x] & mask or col[y] & mask or block[x / 3 * 3 + y / 3] & mask) {
      return false;
    }else {
      row[x] |= mask;
      col[y] |= mask;
      block[x / 3 * 3 + y / 3] |= mask;
      return true;
    }
  }

  void clear(int x, int y, int num) {
    int mask = 1 << (num - 1);
    row[x] ^= mask;
    col[y] ^= mask;
    block[x / 3 * 3 + y / 3] ^= mask;
  }

  static const int N = 9;
  vector<int> row, col, block;
  vector<pair<int, int>> empty;
};

int main(){
  Solution s;
  vector<vector<char> > board;
  board.push_back({'5', '3', '.', '.', '7', '.', '.', '.', '.'});
  board.push_back({'6', '.', '.', '1', '9', '5', '.', '.', '.'});
  board.push_back({'.', '9', '8', '.', '.', '.', '.', '6', '.'});
  board.push_back({'8', '.', '.', '.', '6', '.', '.', '.', '3'});
  board.push_back({'4', '.', '.', '8', '.', '3', '.', '.', '1'});
  board.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
  board.push_back({'.', '6', '.', '.', '.', '.', '2', '8', '.'});
  board.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '5'});
  board.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});
  s.solveSudoku(board);
  for (int i = 0; i < 9; ++i){
    for (int j = 0; j < 9; ++j){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
