#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }else if (nums.size() == 1) {
      return {0};
    }else {
      return productExceptSelf2(nums);
    }
  }

  //O(n) space
  vector<int> productExceptSelf1(vector<int>& nums) {
    int n = nums.size();
    vector<long> leftProduct(n, 0), rightProduct(n, 0);
    leftProduct[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      leftProduct[i] = leftProduct[i - 1] * nums[i];
    }
    rightProduct[n - 1] = nums[n - 1];
    for (int j = n - 2; j >= 0; --j) {
      rightProduct[j] = rightProduct[j + 1] * nums[j];
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        res[0] = rightProduct[1];
      }else if (i == n - 1) {
        res[n - 1] = leftProduct[n - 2];
      }else {
        res[i] = leftProduct[i - 1] * rightProduct[i + 1];
      }
    }
    return res;
  }

  //O(1) space
  vector<int> productExceptSelf2(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    res[n - 1] = nums[n - 1];
    for (int i = n - 2; i > 0; --i) {
      res[i] = res[i + 1] * nums[i];
    }
    int lp = 1;
    for (int i = 0; i < n - 1; ++i) {
      res[i] = lp * res[i + 1];
      lp *= nums[i];
    }
    res[n - 1] = lp;
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {1,2,3,4};
  auto res = s.productExceptSelf(nums);
  print_vec(res);
  return 0;
}
