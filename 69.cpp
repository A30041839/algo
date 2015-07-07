#include "leetcode.h"

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    return sqrt3(x);
  }

  int sqrt1(int x){
    if (x <= 1) {
      return x;
    }
    int low = 0, high = x;
    while (low <= high) {
      int mid = low + (high - low) / 2; //! avoid overflow
      if (mid == x / mid) {
        return mid;
      }else if (mid < x / mid) {
        low = mid + 1;
      }else {
        high = mid - 1;
      }
    }
    return high;
  }

  int sqrt2(int x){
    long long start = -1, end = (long long)x + 1;//!
    while (end - start > 1) {
      long long mid = start + (end - start) / 2;
      if (mid * mid == x) {
        return mid;
      }else if (mid * mid < x) {
        start = mid;
      }else {
        end = mid;
      }
    }
    return (int)start;
  }

  //newton iteration
  int sqrt3(int x){
    if (x == 0) {
      return 0;
    }
    double last, cur = x;
    do {
      last = cur;
      cur = (cur + x / cur) / 2;
    }while (abs(cur - last) > 1e-9);
    return int(cur);
  }
};

int main(){
  Solution s;
  cout << s.mySqrt(0) << endl;
  cout << s.mySqrt(1) << endl;
  cout << s.mySqrt(2) << endl;
  cout << s.mySqrt(10) << endl;
  cout << s.mySqrt(16) << endl;
  cout << s.mySqrt(15) << endl;
  cout << s.mySqrt(2147483647) << endl;
  return 0;
}
