#include "leetcode.h"

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
      res = (res << 1) | (n & 1);
      n >>= 1;
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.reverseBits(43261596) << endl;
  return 0;
}
