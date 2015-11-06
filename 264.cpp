#include "leetcode.h"

using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    return nthUglyNumber1(n);
  }

  int nthUglyNumber1(int n) {
    if (n <= 0) return 0;
    vector<long> res;
    res.push_back(1);
    int i1 = 0, i2 = 0, i3 = 0;
    for (int i = 1; i < n; ++i) {
      long x = res[i1] * 2;
      long y = res[i2] * 3;
      long z = res[i3] * 5;
      long a = min(x, min(y, z));
      res.push_back(a);
      if (a == x) {
        i1++;
      }
      if (a == y) {
        i2++;
      }
      if (a == z) {
        i3++;
      }
    }
    return (int)res[n - 1];
  }

  int nthUglyNumber2(int n) {
    if (n < 1) {
      return 1;
    }
    queue<long> q1, q2, q3;
    q1.push(2);
    q2.push(3);
    q3.push(5);
    long res = 1;
    while (--n) {
      res = min(q1.front(), min(q2.front(), q3.front()));
      if (res == q1.front()) {
        q1.pop();
        q1.push(2 * res);
        q2.push(3 * res);
        q3.push(5 * res);
      }else if (res == q2.front()) {
        q2.pop();
        q2.push(3 * res);
        q3.push(5 * res);
      }else {
        q3.pop();
        q3.push(5 * res);
      }
    }
    return (int)res;
  }
};

int main() {
  Solution s;
  cout << s.nthUglyNumber(1600) << endl;
}
