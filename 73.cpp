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
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> zero_row(m, 0);
    vector<int> zero_col(n, 0);
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j){
        if (matrix[i][j] == 0){
          zero_row[i] = 1;
          zero_col[j] = 1;
        }
      }
    }
    for (int i = 0; i < m; ++i){
      if (zero_row[i] == 1){
        for (int j = 0; j < matrix[0].size(); ++j){
          matrix[i][j] = 0;
        }
      }
    }
    for (int j = 0; j < n; ++j){
      if (zero_col[j] == 1){
        for (int i = 0; i < matrix.size(); ++i){
          matrix[i][j] = 0;
        }
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
