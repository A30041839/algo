#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    return isValidSudoku1(board);
  }

  bool isValidSudoku1(vector<vector<char> >& board){
    if (!board.size()){
      return false;
    }
    int n = 9;
    vector<unordered_set<char> > vec(9, unordered_set<char>());
    vector<unordered_set<char> > row(n, unordered_set<char>());
    vector<unordered_set<char> > col(n, unordered_set<char>());
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        char c = board[i][j];
        if (c != '.'){
          if (vec[i / 3 * 3 + j / 3].count(c) > 0){
            return false;
          }else{
            vec[i / 3 * 3 + j / 3].insert(c);
          }
          if (row[i].count(c) > 0){
            return false;
          }else{
            row[i].insert(c);
          }
          if (col[j].count(c) > 0){
            return false;
          }else{
            col[j].insert(c);
          }
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
