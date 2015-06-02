#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> sol;
    vector<vector<int>> res;
    dfs1(sol, res, 1, k, n);
    return res;
  }

  void dfs1(vector<int>& sol, vector<vector<int>>& res, int start, int k, int remain) {
    if (sol.size() == k and remain == 0) {
      res.push_back(sol);
      return;
    }
    int m = k - sol.size();
    for (int i = start; m > 0 and i <= 9 and (2 * i + m - 1) * m <= 2 * remain; ++i) {
      sol.push_back(i);
      dfs1(sol, res, i + 1, k, remain - i);
      sol.pop_back();
    }
  }
};

int main() {
  Solution s;
  auto res = s.combinationSum3(3, 7);
  for (auto v : res) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
