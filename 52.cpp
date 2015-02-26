#include "leetcode.h"

using namespace std;

class Solution {
private:
  bool check(vector<pair<int, int> >& queens, int i, int j){
    for (auto& queen : queens){
      if (queen.second == j or abs(queen.first - i) == abs(queen.second - j)){
        return false;
      }
    }
    return true;
  }

public:
  int totalNQueens(int n) {
    int ttl = 0;
    vector<pair<int, int> > queens;
    totalNQueens1(n, 0, ttl, queens);
    return ttl;
  }

  void totalNQueens1(int n, int dep, int& ttl, vector<pair<int, int> >& queens) {
    if (dep == n){
      ttl++;
      return;
    }
    for (int i = 0; i < n; ++i){
      if (check(queens, dep, i)){
        queens.push_back({dep, i});
        totalNQueens1(n, dep + 1, ttl, queens);
        queens.pop_back();
      }
    }
  }

};

int main(){
  Solution s;
  cout << s.totalNQueens(4) << endl;
  cout << s.totalNQueens(8) << endl;
  return 0;
}
