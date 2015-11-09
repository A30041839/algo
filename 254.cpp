#include "leetcode.h"
using namespace std;

class Solution {
public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> res;
    vector<int> sub;
    dfs(res, sub, n);
    return res;
  }

  void dfs(vector<vector<int>>& res, vector<int>& sub, int n) {
    for (int k = 2; k <= sqrt(n); ++k) {
      if (n % k == 0) {
        if (sub.empty() or k >= sub.back()) {
          sub.push_back(k);
          dfs(res, sub, n / k);
          sub.pop_back();
        }
      }
    }
    if (!sub.empty()) {
      sub.push_back(n);
      res.push_back(sub);
      sub.pop_back();
    }
  }
};

int main() {
  Solution s;
  int n = 32;
  for (auto res : s.getFactors(n)) {
    print_vec(res);
  }
  return 0;
}
