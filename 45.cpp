#include "leetcode.h"

using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    return jump3(nums);
  }

  int jump1(vector<int>& nums) {
    int n = nums.size();
    int res = 0, cur = 0, last = 0;
    for (int i = 0; i < n; ++i){
      if (i <= cur) {
        if (i > last){
          last = cur;
          res++;
        }
      cur = max(cur, i + nums[i]);
      }
    }
    return cur >= n - 1 ? res : 0;
  }

  int jump2(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 0, cur = 0, res = 0;
    while (start <= end and end < n - 1) {
      for (int i = start; i <= end; ++i) {
        cur = max(cur,  i + nums[i]);
      }
      start = end + 1;
      end = cur;
      res++;
    }
    return start > end ? 0 : res;
  }

  //dp[i] denotes the min steps need to jump to i.
  //dp[k] = min(dp[i] + 1), i < k and i + nums[i] >= k
  //if dp[k] is computed, no need to compute dp[i](i <= k) again, the first dp[k]
  //we get is the minimum.
  int jump3(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = cur + 1; j < n and j <= i + nums[i]; ++j) {
        dp[j] = dp[i] + 1;
        cur = j;
      }
    }
    return dp[n - 1];
  }
};

int main(){
  Solution s;
  vector<int> nums = {2,3,1,1,4};
  cout << s.jump(nums) << endl;
  return 0;
}
