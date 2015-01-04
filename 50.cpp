#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
  double pow(double x, long long n) {
    if (n == 0){
      return 1;
    }else if (n > 0){
      return compute_pow(x, n);
    }else{
      return 1.0 / compute_pow(x, -1 * n);
    }
  }

  double compute_pow(double x, long long n){
    if (n == 1){
      return x;
    }
    if (n & 1){
      return x * compute_pow(x, n - 1);
    }else{
      double ret = compute_pow(x, n >> 1);
      return ret * ret;
    }
  }

};

int main(){
  Solution s;
  cout << s.pow(1, -2147483648) << endl;
  cout << pow(0.00001, 2147483647) << endl;
  return 0;
}
