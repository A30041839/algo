#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > res(n, vector<int>(n, 0));
    if (n < 1){
      return res;
    }
    int k = 1;
    for (int i = 0; i < (n + 1) / 2; ++i){
      for (int j = i; j < i + (n - i * 2) - 1; j++){
        res[i][j] = k++;
      }
      for (int j = i; j < i + (n - i * 2) - 1; j++){
        res[j][n - i - 1] = k++;
      }
      for (int j = i + (n - i * 2) - 1; j > i; j--){
       res[n - i - 1][j] = k++;
      }
      for (int j = i + (n - i * 2) - 1; j > i; j--){
       res[j][i] = k++;
      }
    }
    if (n & 1){
      res[n / 2][n / 2] = k++;
    }
  }
};

int main(){
  Solution s;
  vector<vector<int> > res = s.generateMatrix(5);
  for (int i = 0; i < res.size(); ++i){
    for (int j = 0; j < res.size(); ++j){
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  /*
   * 1 2 3
   * 8 9 4
   * 7 6 5
   */
  return 0;
}
