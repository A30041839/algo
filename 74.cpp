#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() or matrix[0].empty()){
      return false;
    }else{
      return searchMatrix5(matrix, target);
    }
  }

  bool searchMatrix1(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    vector<int> firstCol;
    for (int i = 0; i < m; ++i) {
      firstCol.push_back(matrix[i][0]);
    }
    auto res = binSearch(firstCol, target);
    return res.second
      or (res.first >= 0 and binSearch(matrix[res.first], target).second);
  }

  bool searchMatrix2(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> firstCol;
    for (int i = 0; i < m; ++i) {
      firstCol.push_back(matrix[i][0]);
    }
    int row = lowerBound(firstCol, target);
    if (row < m and firstCol[row] == target) {
      return true;
    }
    if (row == 0) {
      return false;
    }
    int col = lowerBound(matrix[row - 1], target);
    return col < n and matrix[row - 1][col] == target;
  }

  bool searchMatrix3(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    vector<int> firstCol;
    for (int i = 0; i < m; ++i) {
      firstCol.push_back(matrix[i][0]);
    }
    int row = upperBound(firstCol, target);
    if (row == 0) {
      return false;
    }
    int col = upperBound(matrix[row - 1], target);
    return col > 0 and matrix[row - 1][col - 1] == target;
  }

  bool searchMatrix4(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m * n - 1;
    while (low <= high) {
      int mid = (low + high) >> 1;
      int i = mid / n;
      int j = mid % n;
      if (matrix[i][j] == target) {
        return true;
      }else if (matrix[i][j] < target) {
        low = mid + 1;
      }else {
        high = mid - 1;
      }
    }
    return false;
  }

  bool searchMatrix5(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int start = -1, end = m * n;
    while (end - start > 1) {
      int mid = (start + end) >> 1;
      int i = mid / n;
      int j = mid % n;
      if (matrix[i][j] >= target) {
        end = mid;
      }else {
        start = mid;
      }
    }
    return end < n * m and matrix[end / n][end % n] == target;
  }

  pair<int, bool> binSearch(vector<int>& vec, int target) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
      int mid = (low + high) >> 1;
      if (vec[mid] == target) {
        return {mid, true};
      }else if (vec[mid] < target) {
        low = mid + 1;
      }else {
        high = mid - 1;
      }
    }
    return {high, false};
  }

  //return the first i that A[i] >= target
  int lowerBound(vector<int>& vec, int target) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
      int mid = (low + high) >> 1;
      if (vec[mid] >= target) {
        high = mid - 1;
      }else {
        low = mid + 1;
      }
    }
    return low;
  }

  //return the first i that A[i] > target
  int upperBound(vector<int>& vec, int target) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
      int mid = (low + high) >> 1;
      if (vec[mid] <= target) {
        low = mid + 1;
      }else {
        high = mid - 1;
      }
    }
    return low;
  }
};

int main(){
  Solution s;
  vector<vector<int> > matrix;
  matrix.push_back({1, 1});
  if (s.searchMatrix(matrix, 2)){
    cout << "yes" << endl;
  }

  return 0;
}
