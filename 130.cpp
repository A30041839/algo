#include "leetcode.h"

using namespace std;

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    if (!board.size()){
      return;
    }
    int m = board.size();
    int n = board[0].size();
    vector<vector<int> > visit(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j){
        if (visit[i][j] == 0 and board[i][j] == 'O'){
          visit[i][j] = 1;
          bfs(board, visit, i, j, m, n);
        }
      }
    }
  }

  void bfs(vector<vector<char> >& board, vector<vector<int> >& visit, int i, int j,int m, int n) {
    queue<pair<int, int> > q;
    vector<pair<int, int> > tmp;
    q.push({i, j});
    bool f = true;
    while (!q.empty()){
      auto& point = q.front();
      tmp.push_back(point);
      int x = point.first, y = point.second;
      q.pop();
      if (y == n - 1) { 
        if (n > 1){
          f = false;
        }
      }else if (board[x][y + 1] == 'O' and visit[x][y + 1] == 0) {
        visit[x][y + 1] = 1;
        q.push({x, y + 1});
      }
      if (x == m - 1) {
        if (m > 1){
          f = false;
        }
      }else if (board[x + 1][y] == 'O' and visit[x + 1][y] == 0) {
        visit[x + 1][y] = 1;
        q.push({x + 1, y});
      }
      if (y == 0){
        if (n > 1){
          f = false;
        }
      }else if (board[x][y - 1] == 'O' and visit[x][y - 1] == 0) {
        visit[x][y - 1] = 1;
        q.push({x, y - 1});
      }
      if (x == 0){
        if (m > 1){
          f = false;
        }
      }else if (board[x - 1][y] == 'O' and visit[x - 1][y] == 0) {
        visit[x - 1][y] = 1;
        q.push({x - 1, y});
      }
    }
    if (f and (m > 1 or n > 1)){
      for (auto& point : tmp){
        board[point.first][point.second] = 'X';
      }
    }
  }
};

int main(){
  Solution s;
  vector<vector<char> > board;
  board.push_back({'O'});
  /*board.push_back({'X','X','X','O', 'X'});
  board.push_back({'X','O','X','O', 'X'});
  board.push_back({'X','O','X','O', 'X'});
  board.push_back({'X','X','X','X', 'X'});*/
  s.solve(board);
  for (auto& v : board){
    for (auto& x : v){
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
