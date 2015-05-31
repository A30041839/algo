#include "leetcode.h"

using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 0, res = INT_MAX, sum = 0;
    for (; end < n; ++end) {
      sum += nums[end];
      while (sum >= s) {
        res = min(res, end - start + 1);
        sum -= nums[start++];
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {2,3,1,7,4,3};
  cout << s.minSubArrayLen(7, nums) << endl;
  return 0;
}
