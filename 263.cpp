#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isUgly(int num) {
    if (num < 1) {
      return false;
    }
    return isUgly2(num);
  }

  bool isUgly1(int num) {
    if (num == 1) {
      return true;
    }
    if (num % 2 == 0) {
      return isUgly1(num / 2);
    }
    if (num % 3 == 0) {
      return isUgly1(num / 3);
    }
    if (num % 5 == 0) {
      return isUgly1(num / 5);
    }
    return false;
  }

  bool isUgly2(int num) {
    bool f = true;
    while (f and num > 1) {
      f = false;
      if (num % 2 == 0) {
        num /= 2;
        f = true;
      }
      if (num % 3 == 0) {
        num /= 3;
        f = true;
      }
      if (num % 5 == 0) {
        num /= 5;
        f = true;
      }
    }
    return num == 1;
  }
};
