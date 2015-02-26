#include "leetcode.h"

using namespace std;

class Solution {
public:
  int jump(int A[], int n) {
    int res = 0, cur = 0, last = 0;
    for (int i = 0; i < n; ++i){
      if (i > last){
        last = cur;
        res++;
      }
      cur = max(cur, i + A[i]);
    }
    return res;
  }
};

int main(){
  Solution s;
  int A[] = {2,3,1,1,4};
  cout << s.jump(A, 5) << endl;
  return 0;
}
