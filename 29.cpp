#include "leetcode.h"

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0){
      return INT_MAX;
    }
    long long res = divide1(abs((long long)dividend), abs((long long)divisor));
    if ((dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0)){
      res = ~res + 1;
    }
    res = res > INT_MAX ? INT_MAX : res;
    return (int)res;
  }

  long long divide1(long long dividend, long long divisor){
    long long res = 0;
    while (dividend >= divisor){
      long long k = divisor;
      long long m = 1;
      while ((k << 1 > 0) and (k << 1 <= dividend)){
        k = k << 1;
        m = m << 1;
      }
      res += m;
      dividend -= k;
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
