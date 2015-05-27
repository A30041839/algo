#include "leetcode.h"

using namespace std;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    if (board.empty()){
      return false;
    }
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool> > visit(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j){
        if (board[i][j] == word[0]){
          visit[i][j] = true;
          if (exist_dfs(board, visit, i, j, m, n, word.substr(1))){
            return true;
          }
          visit[i][j] = false;
        }
      }
    }
    return false;
  }

private:
  bool is_valid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
  }

  bool exist_dfs(vector<vector<char> >& board, vector<vector<bool> >& visit,
    int curx, int cury, int m, int n, string word) {
    if (word.empty()){
      return true;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = curx + dx[i];
      int ny = cury + dy[i];
      if (is_valid(nx, ny, m, n) and !visit[nx][ny] and board[nx][ny] == word[0]) {
        visit[nx][ny] = true;
        if (exist_dfs(board, visit, nx, ny, m, n, word.substr(1))) {
          return true;
        }
        visit[nx][ny] = false;
      }
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
  string word3 = "ADEEY";

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
