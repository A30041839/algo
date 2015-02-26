#include "leetcode.h"

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    for (int i = 1; i < n; ++i){
      A[i] ^= A[i - 1];
    }
    return A[n - 1];
  }
};

int main(){
  int A[11] = {1, 5, 2, 4, 1, 4, 6, 2, 5, 8, 8};
  Solution s;
  cout << s.singleNumber(A, 11) << endl;
  return 0;
}
