#include "leetcode.h"

using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char> > &board) {
    vector<unordered_set<char> > row(9, unordered_set<char>());
    vector<unordered_set<char> > col(9, unordered_set<char>());
    vector<unordered_set<char> > v(9, unordered_set<char>());
    init(board, row, col, v);
    solveSudoku1(board, row, col, v, 0);
  }

  void init(vector<vector<char> >& board, vector<unordered_set<char> >& row,
            vector<unordered_set<char> >& col, vector<unordered_set<char> >& v){
    for (int i = 0; i < 9; ++i){
      for (int j = 0; j < 9; ++j){
        char c = board[i][j];
        if (c != '.'){
          row[i].insert(c);
          col[j].insert(c);
          v[i / 3 * 3 + j / 3].insert(c);
        }
      }
    }
  }

  bool solveSudoku1(vector<vector<char> >& board, vector<unordered_set<char> >& row,
                    vector<unordered_set<char> >& col, vector<unordered_set<char> >& v, int pos){
    while (pos < 81 and board[pos / 9][pos % 9] != '.'){
      pos++;
    }
    if (pos == 81){
      return true;
    }
    int i = pos / 9;
    int j = pos % 9;
    for (int k = 1; k <= 9; ++k){
      char c = k + '0';
      if (!row[i].count(c) and !col[j].count(c) and !v[i / 3 * 3 + j / 3].count(c)){
        board[i][j] = c;
        row[i].insert(c);
        col[j].insert(c);
        v[i / 3 * 3 + j / 3].insert(c);
        if (solveSudoku1(board, row, col, v, pos + 1)){
          return true;
        }else{
          board[i][j] = '.';
          row[i].erase(c);
          col[j].erase(c);
          v[i / 3 * 3 + j / 3].erase(c);
        }
      }
    }
    return false;
  }
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
