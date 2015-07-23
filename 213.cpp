#include "leetcode.h"

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }else {
      return rob1(nums);
    }
  }


  int _rob(vector<int>::iterator beg, vector<int>::iterator end) {
    vector<int> dp(end - beg, 0);
    dp[0] = *beg;
    for (vector<int>::iterator iter = beg + 1; iter != end; ++iter) {
      dp[iter - beg] = max(*iter + (iter - beg >= 2 ? dp[iter - beg - 2] : 0),
        dp[iter - beg - 1]);
    }
    return dp.back();
  }

  int rob1(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }else {
      return max(_rob(nums.begin(), nums.end() - 1), _rob(nums.begin() + 1, nums.end()));
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {100, 10, 50, 60};
  cout << s.rob(nums) << endl;
  return 0;
}
