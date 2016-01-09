class NumMatrix {
  vector<vector<int>> leftsum;
public:
  NumMatrix(vector<vector<int>> &matrix) {
    if (matrix.empty() or matrix[0].empty()) {
      return;
    }
    int m = matrix.size(), n = matrix[0].size();
    leftsum.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      int tmp = 0;
      for (int j = 0; j < n; ++j) {
        tmp += matrix[i][j];
        leftsum[i][j] = tmp;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int res = 0;
    for (int i = row1; i <= row2; ++i) {
      if (col1 == 0) {
        res += leftsum[i][col2];
      }else {
        res += leftsum[i][col2] - leftsum[i][col1 - 1];
      }
    }
    return res;
  }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
