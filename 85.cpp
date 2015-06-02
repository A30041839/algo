#include "leetcode.h"

using namespace std;

//this question can be projected to Largest Rectangle Problem.
class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.empty() or matrix[0].empty()) {
      return 0;
    }
    int m = matrix.size(), n = matrix[0].size();
    int res = 0;
    vector<int> height(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
      }
      res = max(res, largestRectangleArea(height));
    }
    return res;
  }

private:
  int largestRectangleArea(vector<int>& height) {
    height.push_back(0);
    int n = height.size(), res = 0;
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (s.empty() or height[i] >= height[s.back()]) {
        s.push_back(i);
      }else {
        int h = height[s.back()];
        s.pop_back();
        res = max(res, h * (s.empty() ? i : (i - s.back() - 1)));
        --i;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<vector<char>> matrix;
  matrix.push_back({'1','1','0'});
  matrix.push_back({'1','1','0'});
  matrix.push_back({'1','0','0'});
  cout << s.maximalRectangle(matrix) << endl;
  return 0;
}
