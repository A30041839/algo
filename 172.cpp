#include "leetcode.h"

using namespace std;

class Solution1 {
public:
  int trailingZeroes(int n) {
    int k = 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
      k *= i;
      while (k % 10 == 0){
        k /= 10;
        cnt++;
      }
      k %= (int)(pow(10, (int)log10(i) + 1));
    }
    return cnt;
  }
};

class Solution2 {
public:
  int trailingZeroes(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
      int j = i;
      while (j % 5 == 0){
        j /= 5;
        cnt++;
      }
    }
    return cnt;
  }
};

class Solution {
public:
  int trailingZeroes(int n) {
    int cnt = 0;
    while (n){
      cnt += n / 5;
      n /= 5;
    }
    return cnt;
  }
};

int main(){
  Solution s;
  //cout << s.trailingZeroes(0) << endl;
  //cout << s.trailingZeroes(1) << endl;
  //cout << s.trailingZeroes(10) << endl;
  cout << s.trailingZeroes(625) << endl;
  return 0;
}
