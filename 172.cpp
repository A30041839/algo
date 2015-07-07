#include "leetcode.h"

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    return trailingZeroes1(n);
  }

  int trailingZeroes1(int n) {
    int res = 0;
    while (n) {
      res += n / 5;
      n /= 5;
    }
    return res;
  }

  //TLE
  int trailingZeroes2(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      int k = i;
      while (k % 5 == 0) {
        res++;
        k /= 5;
      }
    }
    return res;
  }

  //TLE
  int trailingZeroes3(int n) {
    int res = 0, k = 1;
    int p = (int)pow(10, (int)log10(n) + 1);
    for (int i = 1; i <= n; ++i) {
      k *= i;
      while (k % 10 == 0) {
        res++;
        k /= 10;
      }
      k %= p;
    }
    return res;
  }
};

int main(){
  Solution s;
  //cout << s.trailingZeroes(0) << endl;
  //cout << s.trailingZeroes(1) << endl;
  //cout << s.trailingZeroes(10) << endl;
  cout << s.trailingZeroes(1808548329) << endl;
  return 0;
}
