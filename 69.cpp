#include "leetcode.h"

using namespace std;

class Solution {
public:
  int sqrt(int x) {
    return sqrt1(x);
  }

  int sqrt1(int x){
    int low = 0, high = x;
    while (low <= high){
      long mid = (low + high) / 2;
      if (mid * mid == x){
        return mid;
      }else if (mid * mid > x){
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }
    return high;
  }
};

int main(){
  Solution s;
  cout << s.sqrt(0) << endl;
  cout << s.sqrt(1) << endl;
  cout << s.sqrt(10) << endl;
  cout << s.sqrt(16) << endl;
  cout << s.sqrt(15) << endl;
  cout << s.sqrt(2147483647) << endl;
  return 0;
}
