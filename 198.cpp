#include "leetcode.h"

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }else {
      return rob2(nums);
    }
  }

  //dp
  int rob1(vector<int>& nums) {
    int n = nums.size();
    //a records curmax including nums[i]
    //b records curmax not including nums[i]
    int a = nums[0], b = 0;
    for (int i = 1; i < n; ++i) {
      int m = nums[i] + b;
      int n = max(a, b);
      a = m;
      b = n;
    }
    return max(a, b);
  }

  //dp[i] indicates the maximum money obtained from robbing 0 to i houses.
  int rob2(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp[i] = max(nums[i] + (i >= 2 ? dp[i - 2] : 0), dp[i - 1]);
    }
    return dp.back();
  }
};

int main() {
  Solution s;
  vector<int> nums = {200, 100, 7, 20, 100};
  cout << s.rob(nums) << endl;
  return 0;
}
