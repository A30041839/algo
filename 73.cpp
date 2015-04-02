#include "leetcode.h"

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {
    if (matrix.size() > 0){
      setZeroes1(matrix);
    }
  }

  void setZeroes1(vector<vector<int> > &matrix) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; ++i) {
      if (matrix[0][i] == 0) {
        flag1 = true;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        flag2 = true;
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[0][j] == 0 or matrix[i][0] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (flag1) {
      for (int i = 0; i < n; ++i) {
        matrix[0][i] = 0;
      }
    }
    if (flag2) {
      for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};

int main(){
  Solution s;
  vector<vector<int>> matrix;
  matrix.push_back({1,2,3});
  matrix.push_back({1,0,3});
  matrix.push_back({1,2,0});
  matrix.push_back({1,2,3});
  s.setZeroes(matrix);
  for (int i = 0; i < matrix.size(); ++i){
    for (int j = 0; j < matrix[0].size(); ++j){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
