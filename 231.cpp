#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }else {
      return isPowerOfTwo3(n);
    }
  }

  bool isPowerOfTwo1(int n) {
    int c = 0;
    for (int i = 0; i < 32; ++i) {
      if ((n >> i) & 1) {
        c++;
      }
    }
    return c == 1;
  }

  bool isPowerOfTwo2(int n) {
    while (n > 1) {
      if (n % 2) {
        return false;
      }
      n /= 2;
    }
    return true;
  }

  bool isPowerOfTwo3(int n) {
    return (n & (n - 1)) == 0;
  }
};

int main(){
  Solution s;
  vector<int> v = {-1, 0, 2, 4, 256, 300};
  for (int i = 0; i < v.size(); ++i) {
    if (s.isPowerOfTwo(v[i])) {
      cout << v[i] << " is power of two!" << endl;
    }
  }
  return 0;
}
