#include "leetcode.h"

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    return firstMissingPositive2(nums);
  }

  //similar to bucket sort, A[i] -> i + 1
  int firstMissingPositive1(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n) {
      if (nums[i] > 0 and nums[i] < n and nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }else {
        i++;
      }
    }
    for (i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }

  int firstMissingPositive2(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] != i + 1) {
        if (nums[i] <= 0 or nums[i] > n or nums[i] == nums[nums[i] - 1]) {
          break;
        }
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }
};

int main(){
  Solution s;
  vector<int> nums = {3};
  cout << s.firstMissingPositive(nums) << endl;
  return 0;
}
