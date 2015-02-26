#include "leetcode.h"

using namespace std;

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    unordered_set<int> s;
    int res = 1;
    for (int i = 0; i < n; ++i){
      s.insert(A[i]);
      int next = A[i] + 1;
      while (s.count(next) > 0){
        next++;
      }
      if (res == A[i]){
        res = next;
      }else if (s.count(next) == 0 and next > 0){
        res = min(next, res);
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  int A[] = {5,-1,9,2,1,6};
  cout << s.firstMissingPositive(A,6) << endl;
  return 0;
}
