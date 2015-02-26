#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    if (!board.size()){
      return false;
    }
    int m = board.size();
    int n = board[0].size();
    vector<vector<int> > visit(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j){
        if (board[i][j] == word[0]){
          visit[i][j] = 1;
          if (exist1(board, visit, i, j, m, n, word.substr(1))){
            return true;
          }
          visit[i][j] = 0;
        }
      }
    }
    return false;
  }

  bool exist1(vector<vector<char> >& board, vector<vector<int> >& visit, int x, int y,
              int m, int n, string word) {
    if (word.empty()){
      return true;
    }
    if (y < n - 1 and board[x][y + 1] == word[0] and visit[x][y + 1] == 0){
      visit[x][y + 1] = 1;
      if (exist1(board, visit, x, y + 1, m, n, word.substr(1))){
        return true;
      }
      visit[x][y + 1] = 0;
    }
    if (x < m - 1 and board[x + 1][y] == word[0] and visit[x + 1][y] == 0){
      visit[x + 1][y] = 1;
      if (exist1(board, visit, x + 1, y, m, n, word.substr(1))){
        return true;
      }
      visit[x + 1][y] = 0;
    }
    if (y > 0 and board[x][y - 1] == word[0] and visit[x][y - 1] == 0){
      visit[x][y - 1] = 1;
      if (exist1(board, visit, x, y - 1, m, n, word.substr(1))){
        return true;
      }
      visit[x][y - 1] = 0;
    }
    if (x > 0 and board[x - 1][y] == word[0] and visit[x - 1][y] == 0){
      visit[x - 1][y] = 1;
      if (exist1(board, visit, x - 1, y, m, n, word.substr(1))){
        return true;
      }
      visit[x - 1][y] = 0;
    }
    return false;
  }
};

int main(){
  Solution s;
  vector<vector<char> > board;
  board.push_back({'A','B','C','E'});
  board.push_back({'S','F','C','S'});
  board.push_back({'A','D','E','E'});
  string word1 = "ABCCED";
  string word2 = "SEE";
  string word3 = "ADEES";

  if (s.exist(board, word1)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
  if (s.exist(board, word2)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
  if (s.exist(board, word3)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
  return 0;
}
