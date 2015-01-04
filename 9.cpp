#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0){
      return false;
    }
    int k = pow(10, (int)log10(x));
    bool res = true;
    while (x > 0){
      if (x / k != x % 10){
        res = false;
        break;
      }
      x %= k;
      x /= 10;
      k /= 100;
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> vec = {0, 11, 100, -1, -100, 11211, -11211, INT_MAX, INT_MIN};
  for (int x : vec){
    if (s.isPalindrome(x)){
      printf("%d is a Palindrome\n", x);
    }else{
      printf("%d is not a Palindrome\n", x);
    }
  }
  return 0;
}
