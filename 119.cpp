#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    if (rowIndex == 0){
      return {1};
    }
    vector<int> res(rowIndex + 1, 0);
    res[0] = res[1] = 1;
    for (int i = 2; i <= rowIndex; ++i){
      int prev = res[0];
      for (int j = 1; j < i; ++j){
        int tmp = res[j];
        res[j] += prev;
        prev = tmp;
      }
      res[i] = 1;
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> res = s.getRow(2);
  for (int a : res){
    cout << a << ",";
  }
  cout << endl;
  return 0;
}
