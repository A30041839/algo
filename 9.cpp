#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    return isPalindrome3(x);
  }

  int getDigit(int x, int n) {
    int m = pow(10, n);
    return x / m % 10;
  }

  bool isPalindrome1(int x) {
    if (x < 0) {
      return false;
    }else if (x == 0) {
      return true;
    }
    int len = (int)log10(x) + 1;
    for (int i = 0; i < len / 2; ++i) {
      if (getDigit(x, i) != getDigit(x, len - i - 1)) {
        return false;
      }
    }
    return true;
  }

  bool isPalindrome2(int x) {
    if (x < 0){
      return false;
    }else if (x == 0) {
      return true;
    }
    int k = (int)log10(x) + 1;
    int m = pow(10, k - 1);
    k /= 2;
    while (k--) {
      if (x / m != x % 10) {
        return false;
      }
      x = x % m / 10;
      m /= 100;
    }
    return true;
  }

  //recursive
  bool _isPalindrome3(int x, int base) {
    if (x == 0) {
      return true;
    }
    return x / base == x % 10 and _isPalindrome3(x % base / 10, base / 100);
  }

  bool isPalindrome3(int x) {
    if (x < 0) {
      return false;
    }else if (x == 0) {
      return true;
    }
    int base = pow(10, (int)log10(x));
    return _isPalindrome3(x, base);
  }
};

int main(){
  Solution s;
  vector<int> vec = {0, 10, 11, 100, -1, -100, 11211, -11211, 1410110141};
  for (int x : vec){
    if (s.isPalindrome(x)){
      printf("%d is a Palindrome\n", x);
    }else{
      printf("%d is not a Palindrome\n", x);
    }
  }
  return 0;
}
