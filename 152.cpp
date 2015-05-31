#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    return maxProduct2(nums);
  }

  //O(n) space
  int maxProduct1(vector<int>& nums) {
    int n = nums.size();
    vector<int> positive_max(n, 0);
    vector<int> negative_min(n, 0);
    int res = nums[0];
    positive_max[0] = nums[0] > 0 ? nums[0] : 0;
    negative_min[0] = nums[0] < 0 ? nums[0] : 0;
    for (int i = 1; i < n; ++i){
      if (nums[i] > 0){
        positive_max[i] = max(positive_max[i - 1] * nums[i], nums[i]);
        negative_min[i] = negative_min[i - 1] * nums[i];
      }else if (nums[i] < 0){
        positive_max[i] = negative_min[i - 1] * nums[i];
        negative_min[i] = min(positive_max[i - 1] * nums[i], nums[i]);
      }
      res = max(res, positive_max[i]);
    }
    return res;
  }

  //O(1) space
  int maxProduct2(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    int res = 0, pos_max = 0, neg_min = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < 0) {
        int tmp = pos_max;
        pos_max = neg_min * nums[i];
        neg_min = min(tmp * nums[i], nums[i]);
      }else if (nums[i] > 0) {
        pos_max = max(pos_max * nums[i], nums[i]);
        neg_min *= nums[i];
      }else {
        pos_max = neg_min = 0;
      }
      res = max(res, pos_max);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {-4,-3,-2};
  cout << s.maxProduct(nums) << endl;
  return 0;
}
