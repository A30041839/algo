#include "leetcode.h"

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int mid = (m + n) / 2;
    if ((m + n) % 2){
      return findKthSmallestSortedArrays(A, m, B, n, mid + 1);
    }else{
      return (findKthSmallestSortedArrays(A, m, B, n, mid) +
              findKthSmallestSortedArrays(A, m, B, n, mid + 1)) / 2.0;
    }
  }

  int findKthSmallestSortedArrays(int A[], int m, int B[], int n, int k){
    if (m > n){
      return findKthSmallestSortedArrays(B, n, A, m, k);
    }
    if (m == 0){
      return B[k - 1];
    }
    if (k == 1){
      return min(A[0], B[0]);
    }
    int i = min(k / 2, m);
    int j = k - i;
    if (A[i - 1] > B[j - 1]){
      return findKthSmallestSortedArrays(A, m, B + j, n - j, k - j);
    }else if (A[i - 1] < B[j - 1]){
      return findKthSmallestSortedArrays(A + i, m - i, B, n, k - i);
    }else{
      return A[i - 1];
    }
  }
};

int main(){
  Solution s;
  int A[] = {-1, 1, 3, 6, 6, 7};
  int B[] = {2,4,9};
  cout << s.findMedianSortedArrays(A, 6, B, 3) << endl;
  return 0;
}
