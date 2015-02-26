#include "leetcode.h"

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    int res = 0;
    for (int i = 0; i < 32; ++i){
      int sum = 0;
      for (int j = 0; j < n; ++j){
        sum += (A[j] >> i) & 1;
      }
      res |= (sum % 3) << i;
    }
    return res;
  }
};

int main(){
  int A[11] = {1, -5, 2, 1, 2, 1, 2};
  Solution s;
  cout << s.singleNumber(A, 7) << endl;
  return 0;
}
