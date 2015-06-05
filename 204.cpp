#include "leetcode.h"

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }else {
      return countPrimes1(n);
    }
  }

  int countPrimes1(int n) {
    vector<bool> isPrime(n, true);
    int res = 0;
    for (int i = 2; i * i < n; ++i) {
      if (!isPrime[i]) {
        continue;
      }
      for (int j = i * i; j < n; j += i) {
        isPrime[j] = false;
      }
    }
    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {
        res++;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.countPrimes(1000000) << endl;
  return 0;
}
