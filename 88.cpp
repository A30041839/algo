#include "leetcode.h"

using namespace std;

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    int i = m + n - 1;
    m--;
    n--;
    while (m >= 0 and n >=0) {
      A[i--] = A[m] > B[n] ? A[m--] : B[n--];
    }
    while (n >= 0) {
      A[i--] = B[n--];
    }
  }
};

int main(){
  int A[6] = {1, 3, 5, 0, 0};
  int B[2] = {-1, 0};
  Solution s;
  s.merge(A, 3, B, 2);
  print_array(A, 5);
  return 0;
}
