#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    return isValidSudoku2(board);
  }

  bool isValidSudoku1(vector<vector<char> >& board){
    if (board.empty() or board[0].empty()){
      return false;
    }
    int n = 9;
    vector<unordered_set<char> > vec(n, unordered_set<char>());
    vector<unordered_set<char> > row(n, unordered_set<char>());
    vector<unordered_set<char> > col(n, unordered_set<char>());
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        char c = board[i][j];
        if (c != '.'){
          if (vec[i / 3 * 3 + j / 3].count(c)){
            return false;
          }else{
            vec[i / 3 * 3 + j / 3].insert(c);
          }
          if (row[i].count(c)){
            return false;
          }else{
            row[i].insert(c);
          }
          if (col[j].count(c)){
            return false;
          }else{
            col[j].insert(c);
          }
        }
      }
    }
    return true;
  }

  //bit manipulation
  bool isValidSudoku2(vector<vector<char> >& board){
    if (board.empty() or board[0].empty()) {
      return false;
    }
    vector<int> block(9, 0), col(9, 0), row(9, 0);
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c == '.') {
          continue;
        }
        int musk = 1 << (c - '1');
        if (row[i] & musk or col[j] & musk or block[i / 3 * 3 + j / 3] & musk) {
          return false;
        }else {
          row[i] |= musk;
          col[j] |= musk;
          block[i / 3 * 3 + j / 3] |= musk;
        }
      }
    }
    return true;
  }
};

int main(){
  Solution s;
  return 0;
}
