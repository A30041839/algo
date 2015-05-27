#include "leetcode.h"

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    if (matrix.empty() or matrix[0].empty()) {
      return;
    }
    rotate2(matrix);
  }

  void rotate1(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; ++i){
      for (int j = i; j < n - i - 1; ++j){
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = tmp;
      }
    }
  }

  void rotate2(vector<vector<int> > &matrix) {
    //first upside down, then rotate by the main diagonal
    int n = matrix.size();
    for (int row = 0; row < n / 2; ++row) {
      swap(matrix[row], matrix[n - row - 1]);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

int main(){
  Solution s;
  vector<vector<int> > matrix;
  /* 1 2 3
   * 4 5 6
   * 7 8 9
   *
   * 7 4 1
   * 8 5 2
   * 9 6 3
   */
  int k = 1;
  for (int i = 0; i < 5; ++i){
    matrix.push_back(vector<int>());
    for (int j = 0; j < 5; ++j){
      matrix[i].push_back(k++);
    }
  }
  s.rotate(matrix);
  for (int i = 0; i < 5; ++i){
    for (int j = 0; j < 5; ++j){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
