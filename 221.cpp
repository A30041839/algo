#include "leetcode.h"
using namespace std;

class Solution {
private:
  int helper(vector<int>& height) {
    vector<int> v;
    height.push_back(-1);
    int n = height.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (v.empty() or height[i] >= height[v.back()]) {
        v.push_back(i);
      }else {
        int j = v.back();
        v.pop_back();
        int width = v.empty() ? i : i - v.back() - 1;
        if (width >= height[j]) {
          res = max(res, height[j] * height[j]);
        }
        i--;
      }
    }
    height.pop_back();
    return res;
  }

public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() or matrix[0].empty()) {
      return 0;
    }
    int m = matrix.size(), n = matrix[0].size();
    vector<int> height(n, 0);
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        height[j] += (matrix[i][j] - '0');
        if (matrix[i][j] == '0') {
          height[j] = 0;
        }
      }
      res = max(res, helper(height));
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<char>> matrix;
  matrix.push_back({'1','0','1','0','0'});
  matrix.push_back({'1','0','1','1','1'});
  matrix.push_back({'1','1','1','1','1'});
  matrix.push_back({'1','0','0','1','0'});
  cout << s.maximalSquare(matrix) << endl;
}
