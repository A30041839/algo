#include "leetcode.h"

using namespace std;

class Solution {
public:
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
  int A[6] = {1, 1, 1, 1, 1, 2};
  Solution s;
  int len = s.removeElement(A, 6, 1);
  for (int i = 0; i < len; ++i){
    cout << A[i] << ",";
  }
  cout << endl;
  return 0;
}
