#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    if (matrix.size() == 0){
      return res;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int k = min((m + 1) / 2, (n + 1) / 2);
    for (int i = 0; i < k; ++i){
      for (int j = i; j < i + (n - i * 2) - 1; ++j) {
        res.push_back(matrix[i][j]);
      }
      for (int j = i; j < i + (m - i * 2) - 1; ++j) {
        res.push_back(matrix[j][n - i - 1]);
      }
      for (int j = i + (n - i * 2) - 1; (j > i and m > 1) or (j >= n - 1 and m == 1 and n > 1); --j) {
        res.push_back(matrix[m - i  - 1][j]);
      }
      for (int j = i + (m - i * 2) - 1; (j > i and n  > 1) or (j >= m - 1 and n == 1 and m > 1); --j) {
        res.push_back(matrix[j][i]);
      }
    }
    if (m == n and m & 1){
      res.push_back(matrix[m / 2][n / 2]);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<vector<int> > matrix;
  matrix.push_back({1});
  matrix.push_back({2});
  vector<int> res = s.spiralOrder(matrix);
  for (int i : res){
    cout << i << ",";
  }
  cout << endl;
  return 0;
}
