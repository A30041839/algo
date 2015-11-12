#include "leetcode.h"

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    return findPeakElement2(nums);
  }

  int findPeakElement1(vector<int> &nums, int low, int high) {
    if (low > high) {
      return -1;
    }
    int mid = (low + high) >> 1;
    bool left = mid > 0 ? (nums[mid] > nums[mid - 1]) : true;
    bool right = mid < nums.size() - 1 ? (nums[mid] > nums[mid + 1]) : true;
    if (left and right) {
      return mid;
    }
    int lpeak = findPeakElement1(nums, low, mid - 1);
    if (lpeak != -1) {
      return lpeak;
    }
    return findPeakElement1(nums, mid + 1, high);
  }

  int findPeakElement2(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (mid > 0 and nums[mid] < nums[mid - 1]) {
        high = mid - 1;
      }else if (mid < n - 1 and nums[mid + 1] > nums[mid]) {
        low = mid + 1;
      }else {
        return mid;
      }
    }
    return low;
  }
};

int main(){
  vector<int> v = {INT_MIN};
  Solution s;
  cout << s.findPeakElement(v) << endl;
  return 0;
}
