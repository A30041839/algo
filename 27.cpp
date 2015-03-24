#include "leetcode.h"

using namespace std;

class Solution {
public:
  //O(n) solution, similar with partition algorithm
  //in quick sort.
  int removeElement(int A[], int n, int elem) {
    int i = -1;
    for (int j = 0; j < n; ++j){
      if (A[j] != elem){
        swap(A[++i], A[j]);
      }
    }
    return i + 1;
  }
};

int main(){
  Solution s;
  int A[6] = {1, 1, 1, 1, 1, 2};
  int len = s.removeElement(A, 6, 1);
  print_array(A, len);
  return 0;
}
