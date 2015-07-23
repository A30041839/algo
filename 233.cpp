#include "leetcode.h"

using namespace std;

class Solution {
public:
  int countDigitOne(int n) {
    if (n < 0) {
      return 0;
    }
    return countDigitOne1(n);
  }

  int countDigitOne1(int n) {
    if (n == 0 or n == 1) {
      return n;
    }
    int l = log10(n);
    int base = pow(10, l);
    int r = countDigitOne1(base - 1);
    int res = countDigitOne1(n % base) + (n / base) * r;
    if (n >= base * 2) {
      res += base;
    }else {
      res += n - base + 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.countDigitOne(1) << endl;
  return 0;
}
