#include "leetcode.h"

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size(), res, minv = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 and nums[i] == nums[i - 1]) {
        continue;
      }
      int start = i + 1, end = n - 1;
      while (start < end) {
        int sum = nums[i] + nums[start] + nums[end];
        if (sum == target) {
          return target;
        }else if (sum > target) {
          end--;
        }else {
          start++;
        }
        if (minv > abs(sum - target)) {
          minv = abs(sum - target);
          res = sum;
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {0,2,1,-3};
  cout << s.threeSumClosest(nums, 1) << endl;
  return 0;
}
