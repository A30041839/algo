#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxSubArray(int A[], int n) {
    return maxSubArray1(A, n);
  }

  int maxSubArray1(int A[], int n){
    vector<int> dp(n , 0);
    dp[0] = A[0];
    int maxSum = A[0];
    for (int i = 1; i < n; ++i){
      dp[i] = dp[i - 1] > 0 ? dp[i - 1] + A[i] : A[i];
      maxSum = max(dp[i], maxSum);
    }
    return maxSum;
  }
};

int main(){
  Solution s;
  int A[9] = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(A, 9) << endl;
  return 0;
}
