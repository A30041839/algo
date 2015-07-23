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
  int totalNQueens(int n) {
    int res = 0;
    vector<int> hash(n, -1);
    dfs(res, hash, n, 0);
    return res;
  }

  void dfs(int& res, vector<int>& hash, int n, int row) {
    if (row == n) {
      res++;
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (check(hash, row, col)) {
        hash[row] = col;
        dfs(res, hash, n, row + 1);
      }
    }
  }
};

int main(){
  Solution s;
  int n = 4;
  cout << s.totalNQueens(n) << endl;
  return 0;
}
