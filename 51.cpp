#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string> solution;
    vector<pair<int, int> > queens;
    solveNQueens1(res, solution, queens, n, 0);
    return res;
  }

  void solveNQueens1(vector<vector<string> >& res, vector<string>& solution,
                     vector<pair<int, int> >& queens, int n, int dep){
    if (dep == n){
      res.push_back(solution);
      return;
    }
    for (int i = 0; i < n; ++i){
      if (check_column(queens, i)){
        if (check_diagnal(queens, dep, i)){ 
          queens.push_back({dep, i});
          string row(n, '.');
          row[i] = 'Q';
          solution.push_back(row);
          solveNQueens1(res, solution, queens, n, dep + 1);
          solution.pop_back();
          queens.pop_back();
        }
      }
    }
  }

  bool check_column(vector<pair<int, int> >& queens, int i){
    for (auto& p : queens){
      if (p.second == i){
        return false;
      }
    }
    return true;
  }

  bool check_diagnal(vector<pair<int, int> >& queens, int i, int j){
    for (auto& p : queens){
      if (abs(p.first - i) == abs(p.second - j)){
        return false;
      }
    }
    return true;
  }
};


int main(){
  Solution s;
  vector<vector<string> > res = s.solveNQueens(8);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < 8; ++j){
      cout << res[i][j] << endl;
    }
    cout << endl;
  }
  return 0;
}
