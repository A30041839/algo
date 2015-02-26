#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxProduct(int A[], int n) {
    return maxProduct1(A, n);
  }

  int maxProduct1(int A[], int n) {
    vector<int> positive_max(n, 0);
    vector<int> negative_min(n, 0);
    int res = A[0];
    positive_max[0] = A[0] > 0 ? A[0] : 0;
    negative_min[0] = A[0] < 0 ? A[0] : 0;
    for (int i = 1; i < n; ++i){
      if (A[i] > 0){
        positive_max[i] = max(positive_max[i - 1] * A[i], A[i]);
        negative_min[i] = negative_min[i - 1] * A[i];
      }else if (A[i] < 0){
        positive_max[i] = negative_min[i - 1] * A[i];
        negative_min[i] = min(positive_max[i - 1] * A[i], A[i]);
      }
      res = max(res, positive_max[i]);
    }
    return res;
  }
};

int main(){
  Solution s;
  int A[] = {-2,0};
  cout << s.maxProduct(A, 2) << endl;
  return 0;
}
