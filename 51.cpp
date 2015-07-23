#include "leetcode.h"

using namespace std;

class Solution {
  bool check(vector<int>& hash, int row, int col) {
    for (int k = 0; k < row; ++k) {
      if (hash[k] == col or row - k == abs(col - hash[k])) {
        return false;
      }
    }
    return true;
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> sol;
    vector<int> hash(n, -1);
    dfs(res, sol, hash, n, 0);
    return res;
  }

  void dfs(vector<vector<string>>& res, vector<string>& sol, vector<int>& hash,
    int n, int row) {
    if (row == n) {
      res.push_back(sol);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (check(hash, row, col)) {
        hash[row] = col;
        string tmp(n, '.');
        tmp[col] = 'Q';
        sol.push_back(tmp);
        dfs(res, sol, hash, n, row + 1);
        sol.pop_back();
      }
    }
  }
};

int main(){
  Solution s;
  int n = 4;
  vector<vector<string>> res = s.solveNQueens(n);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < n; ++j){
      cout << res[i][j] << endl;
    }
    cout << endl;
  }
  return 0;
}
