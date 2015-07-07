#include "leetcode.h"

using namespace std;

class Solution {
private:
  int sgn(int x) {
    return x >= 0 ? 1 : -1;
  }

public:
  int reverse(int x) {
    return reverse3(x);
  }

  int reverse1(int x) {
    int sign = sgn(x);
    int res = 0;
    x = abs(x);
    while (x > 0) {
      if (res > INT_MAX / 10) {
        return 0;
      }
      res *= 10;
      if (res > INT_MAX - x % 10) {
        return 0;
      }
      res += x % 10;
      x /= 10;
    }
    return sign * res;
  }

  int reverse2(int x) {
    int sign = sgn(x);
    int res = 0;
    long long tmp;
    x = abs(x);
    while (x > 0) {
      tmp = res;
      if (res * 10 != tmp * 10) {
        return 0;
      }
      res *= 10;
      if (res + x % 10 < 0) {
        return 0;
      }
      res += x % 10;
      x /= 10;
    }
    return sign * res;
  }

  int reverse3(int x) {
    long res = 0;
    while (x != 0) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return (res > INT_MAX or res < INT_MIN) ? 0 : res;
  }
};

int main(){
  Solution s;
  cout << s.reverse(-123) << endl;
  cout << s.reverse(1534236469) << endl;

  return 0;
}
