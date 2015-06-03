#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    return search1(nums, target);
  }

  bool search1(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      while (low < high and nums[low] == nums[high]) {
        low++;
      }
      int mid = (low + high) >> 1;
      if (nums[mid] == target) {
        return true;
      }else if (nums[low] <= nums[mid]) {
        if (nums[low] <= target and target < nums[mid]) {
          high = mid - 1;
        }else {
          low = mid + 1;
        }
      }else {
        if (nums[mid] < target and target <= nums[high]) {
          low = mid + 1;
        }else {
          high = mid - 1;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {5,5,6,6,6,6,6,6,7,1,2,3,4,5};
  if (s.search(nums, -1)) {
    cout << "yes" << endl;
  }
  return 0;
}
