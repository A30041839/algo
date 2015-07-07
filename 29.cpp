#include "leetcode.h"

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0) {
      return INT_MAX;
    }
    bool neg = (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0) ?
      true : false;
    long _dividend = abs((long)dividend), _divisor = abs((long)divisor);
    long res = _divide(_dividend, _divisor);
    res = neg ? ~res + 1 : res;
    return res > INT_MAX or res < INT_MIN ? INT_MAX : (int)res;
  }

  long _divide(long dividend, long divisor) {
    long res = 0;
    while (dividend >= divisor) {
      long k = 1, d = divisor;
      while (dividend >= d << 1) {
        k <<= 1;
        d <<= 1;
      }
      dividend -= d;
      res |= k;
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.divide(-1010369383, -2147483648) << endl;
  cout << s.divide(-2147483648, -1) << endl;
  cout << s.divide(-2147483648, 1) << endl;
  cout << s.divide(10, -17) << endl;
  cout << s.divide(-1992, 17) << endl;
  return 0;
}
