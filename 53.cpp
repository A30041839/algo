#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }else {
      return maxSubArray3(nums, 0, nums.size() - 1);
    }
  }

  //O(n) space
  int maxSubArray1(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n , 0);
    dp[0] = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < n; ++i){
      dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
      maxSum = max(dp[i], maxSum);
    }
    return maxSum;
  }

  //O(1) space
  int maxSubArray2(vector<int>& nums){
    int n = nums.size();
    int prev = 0, res = INT_MIN;
    for (int i = 0; i < n; ++i) {
      prev = prev > 0 ? prev + nums[i] : nums[i];
      res = max(res, prev);
    }
    return res;
  }

  int maxSubArray3(vector<int>& nums, int start, int end){
    if (start > end) {
      return INT_MIN;
    }
    if (start == end) {
      return nums[start];
    }
    int mid = (start + end) >> 1;
    int lmax = maxSubArray3(nums, start, mid - 1);
    int rmax = maxSubArray3(nums, mid + 1, end);
    int sum = nums[mid];
    int res = sum;
    for (int i = mid - 1; i >= start; --i) {
      sum += nums[i];
      res = max(res, sum);
    }
    sum = res;
    for (int i = mid + 1; i <= end; ++i) {
      sum += nums[i];
      res = max(res, sum);
    }
    return max(res, max(lmax, rmax));
  }
};

int main(){
  Solution s;
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(nums) << endl;
  return 0;
}
