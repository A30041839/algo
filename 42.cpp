#include "leetcode.h"

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
      return 0;
    }else {
      return trap2(height, n);
    }
  }

  int trap1(vector<int>& A, int n) {
    int lmax[n], rmax[n];
    lmax[0] = A[0];
    int res = 0;
    for (int i = 1; i < n; ++i) {
      lmax[i] = max(A[i], lmax[i - 1]);
    }
    rmax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      rmax[i] = max(A[i], rmax[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
      res += min(lmax[i], rmax[i]) - A[i];
    }
    return res;
  }

  int trap2(vector<int>& A, int n) {
    int lmax[n];
    int res = 0, rmax = 0;
    lmax[0] = A[0];
    for (int i = 1; i < n; ++i) {
      lmax[i] = max(A[i], lmax[i - 1]);
    }
    for (int i = n - 1; i >= 0; --i) {
      rmax = max(rmax, A[i]);
      res += min(lmax[i], rmax) - A[i];
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> A = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << s.trap(A) << endl;
  return 0;
}
