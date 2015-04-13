#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    vector<string> res;
    if (n == 0) {
      res.push_back(get_range(lower, upper));
      return res;
    }
    int prev = lower - 1;
    for (int i = 0; i < n; ++i) {
      if (A[i] - prev > 1) {
        res.push_back(get_range(prev + 1, A[i] - 1));
      }
      prev = A[i];
    }
    if (upper > prev) {
      res.push_back(get_range(prev + 1, upper));
    }
    return res;
  }

  string get_range(int low, int high) {
    char tmp[10];
    if (low == high) {
      sprintf(tmp, "%d", low);
    } else {
      sprintf(tmp, "%d->%d", low, high);
    }
    return string(tmp);
  }
};

int main(){
  Solution s;
  int A[] = {1,3,5};
  vector<string> res = s.findMissingRanges(A, 3, 1, 80);
  print_vec<string>(res);
  return 0;
}
