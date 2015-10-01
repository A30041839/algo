#include "leetcode.h"

using namespace std;

class Solution {
public:
  int addDigits(int num) {
    //digital root
    //https://en.wikipedia.org/wiki/Digital_root
    return num - 9 * ((num - 1) / 9);
  }
};
