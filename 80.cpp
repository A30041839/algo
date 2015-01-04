#include <iostream>

using namespace std;

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
      if (next > low + 1){
        A[k + 1] = A[k];
        A[k + 2] = A[next];
        k += 2;
      }else{
        A[++k] = A[next];
      }
      low = next;
    }
    if (low < n - 1){
      A[k + 1] = A[k];
      k += 2;
    }else{
      k++;
    }
    return k;
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
  int a[3] = {1,1,1};
  Solution s;
  int len = s.removeDuplicates(a, 3);
  for (int i = 0; i < len; ++i){
    cout << a[i] << ",";
  }
  cout << endl;
  return 0;
}
