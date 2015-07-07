#include "leetcode.h"

using namespace std;

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    return rangeBitwiseAnd1(m, n);
  }

  int rangeBitwiseAnd1(int m, int n) {
    int res = 0, mask;
    for (int i = 31; i >= 0; --i) {
      mask = 1 << i;
      if (m & mask) {
        if ((mask << 1) - (m & ((mask << 1) - 1)) <= n - m) {
          //the range could shift current bit to zero
          //the lower 1 bits can also be shifted to zero
          break;
        }else {
          res |= mask;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.rangeBitwiseAnd(5, 7) << endl;
  cout << s.rangeBitwiseAnd(3, 4) << endl;
  return 0;
}
