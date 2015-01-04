#include <iostream>

using namespace std;

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >=0 and j >= 0){
      A[k--] = A[i] > B[j] ? A[i--] : B[j--];
    }
    while (j >= 0){
      A[k--] = B[j--];
    }
  }
};

int main(){
  int A[6] = {1, 3, 5, 0, 0};
  int B[2] = {-1, 0};
  Solution s;
  s.merge(A, 3, B, 2);
  for (int k = 0; k < 5; ++k){
    cout << A[k] << ",";
  }
  cout << endl;
  return 0;
}
