#include "leetcode.h"

using namespace std;

class Solution1 {
public:
  int removeDuplicates(int A[], int n) {
    if (n == 0){
      return 0;
    }
    int k = 0;
    for (int i = 1; i < n; ++i){
      if (A[k] != A[i]){
        A[++k] = A[i];
      }
    }
    return k + 1;
  }
};

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n == 0){
      return 0;
    }
    int k = 0;
    int next = 0;
    int low = 0;
    while ((next = find(A, low, n - 1, A[k])) != -1){
      A[++k] = A[next];
      low = next + 1;
    }
    return k + 1;
  }

  int find(int A[], int low, int high, int x){
    int mid = 0;
    int _high = high;
    while (low <= high){
      mid = (low + high) / 2;
      if (A[mid] == x){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
    return low > _high ? -1 : low;
  }
};

int main(){
  int a[6] = {1, 2, 3, 4, 4, 5};
  Solution s;
  int len = s.removeDuplicates(a, 6);
  for (int i = 0; i < len; ++i){
    cout << a[i] << ",";
  }
  cout << endl;
  return 0;
}
