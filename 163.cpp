#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    vector<string> res = {};
    char tmp[10];
    if (n == 0) {
      if (lower == upper) {
        sprintf(tmp, "%d", lower);
        res.push_back(string(tmp));
      }else {
        sprintf(tmp, "%d->%d", lower, upper);
        res.push_back(string(tmp));
      }
      return res;
    }
    int prev = lower - 1;
    for (int i = 0; i < n; ++i) {
      if (A[i] > prev + 2){
        sprintf(tmp, "%d->%d", prev + 1, A[i] - 1);
        res.push_back(string(tmp));
      }else if (A[i] == prev + 2) {
        sprintf(tmp,"%d", A[i] - 1);
        res.push_back(string(tmp));
      }
      prev = A[i];
    }
    if (A[n - 1] == upper - 1) {
      sprintf(tmp,"%d", upper);
      res.push_back(string(tmp));
    }else if (A[n - 1] < upper - 1) {
      sprintf(tmp, "%d->%d", A[n - 1] + 1, upper);
      res.push_back(string(tmp));
    }
    return res;
  }
};

int main(){
  Solution s;
  int A[] = {0, 1, 3, 50, 99};
  vector<string> res = s.findMissingRanges(A, 0, 0, 0);
  for (auto& range : res){
    cout << range << ",";
  }
  cout <<endl;
  return 0;
}
