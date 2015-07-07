#include "leetcode.h"

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    return hammingWeight2(n);
  }

  int hammingWeight1(uint32_t n) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      if (n & 1) {
        res++;
      }
      n >>= 1;
    }
    return res;
  }

  int hammingWeight2(uint32_t n) {
    int res = 0;
    while (n) {
      n &= (n - 1); //each time set the lowest 1 bit to 0
      res++;
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.hammingWeight(11) << endl;
  return 0;
}
