#include "leetcode.h"

using namespace std;

class Solution {
public:
  int trap(int A[], int n) {
    if (n <= 2) {
      return 0;
    }
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);
    int res = 0;
    int l = A[0];
    for (int i = 1; i < n; ++i) {
      lmax[i] = l;
      l = max(l, A[i]);
    }
    int r = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      rmax[i] = r;
      r = max(r, A[i]);
    }
    for (int i = 0; i < n; ++i) {
      int ctrap = min(lmax[i], rmax[i]) - A[i];
      res = ctrap > 0 ? res + ctrap : res;
    }
    return res;
  }
};

int main(){
  Solution s;
  int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  //int A[] = {1,0,1};
  //int A[] = {1,2,3};
  //int A[] = {2,1,0,2};
  cout << s.trap(A, 12) << endl;
  return 0;
}
