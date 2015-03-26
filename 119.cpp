#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1, 1);
    for (int i = 0; i < rowIndex + 1; ++i) {
      for (int j = i - 1; j >= 1; --j) {
        res[j] += res[j - 1];
      }
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
