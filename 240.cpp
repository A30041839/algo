#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() or matrix[0].empty()) {
      return false;
    }else {
      return search1(matrix, target);
    }
  }

  bool search1(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i >= 0 and j >= 0 and i < m and j < n) {
      if (matrix[i][j] == target) {
        return true;
      }else if (matrix[i][j] > target) {
        j--;
      }else {
        i++;
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  vector<vector<int>> matrix;
  matrix.push_back({1,2,3});
  matrix.push_back({2,3,4});
  matrix.push_back({5,6,7});
  matrix.push_back({9,10,11});
  vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,-1};
  for (auto x : v) {
    if (s.searchMatrix(matrix, x)) {
      cout << "matrix contains " << x << endl;
    }
  }
  return 0;
}
