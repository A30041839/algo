#include "leetcode.h"

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n < 0) {
      return 1.0 / compute_pow2(x, -1 * (long)n);
    }else {
      return compute_pow2(x, n);
    }
  }

  //recursive
  double compute_pow1(double x, long n){
    if (n == 0) {
      return 1;
    }
    double ret = compute_pow1(x, n >> 1);
    return n & 1 ? x * ret * ret : ret * ret;
  }

  //iterative
  //consider n as binary
  double compute_pow2(double x, long n){
    double res = 1;
    while (n) {
      if (n & 1) {
        res *= x;
      }
      x *= x;
      n >>= 1;
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.myPow(2, -10) << endl;
  return 0;
}
