#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i <= n - 3; ++i) {
      if (i > 0 and nums[i] == nums[i - 1]) {
        continue;
      }
      int sum = -1 * nums[i];
      int l = i + 1, r = n - 1;
      while (l < r) {
        int cur = nums[l] + nums[r];
        if (cur == sum) {
          res.push_back({nums[i], nums[l++], nums[r--]});
          while (l < r and nums[l] == nums[l - 1]) {
            l++;
          }
          while (l < r and nums[r] == nums[r + 1]) {
            r--;
          }
        }else {
          cur > sum ? r-- : l++;
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {-1,0,1,2,-1,-4};
  for (auto& sol : s.threeSum(nums)) {
    for (int x : sol) {
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
