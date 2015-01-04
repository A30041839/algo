#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int res = 0;
    int y = x > 0 ? x : -1 * x;
    int sgn = x > 0 ? 1 : -1;
    while (y != 0){
      if (res > INT_MAX / 10){
        return 0;
      }
      res *= 10;
      int c = y % 10;
      if (res > INT_MAX - c){
        return 0;
      }
      res += c;
      y /= 10;
    }
    return sgn * res;
  }
};

int main(){
  Solution s;
  cout << s.reverse(1534236469) << endl;

  return 0;
}
