#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0){
      return false;
    }else{
      return searchMatrix1(matrix, target);
    }
  }

  bool searchMatrix1(vector<vector<int> >& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int x1 = 0, x2 = m - 1, y1 = 0, y2 = n - 1;
    while (x1 <= x2 and y1 <= y2){
      if (matrix[x1][y1] == target){
        return true;
      }
      bool f = false;
      while (x1 < m - 1 and matrix[x1][y2] < target){
        x1++;
        f = true;
      }
      while (x2 > 0 and matrix[x2][y1] > target){
        x2--;
        f = true;
      }
      while (y2 > 0 and matrix[x1][y2] > target){
        y2--;
        f = true;
      }
      while (y1 < n - 1 and matrix[x2][y1] < target){
        y1++;
        f = true;
      }
      if (!f){
        break;
      }
    }
    return false;
  }

};

int main(){
  Solution s;
  vector<vector<int> > matrix;
  matrix.push_back({1, 3});
  if (s.searchMatrix(matrix, 2)){
    cout << "yes" << endl;
  }

  return 0;
}
