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

  //notice nums[i] != nums[i + 1]
  int findPeakElement2(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return 0;
    }
    if (nums[0] > nums[1]) {
      return 0;
    }
    if (nums[n - 1] > nums[n - 2]) {
      return n - 1;
    }
    int start = 1, end = n - 2;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]) {
        return mid;
      }else if (nums[mid - 1] > nums[mid]) {
        end = mid - 1;
      }else {
        start = mid + 1;
      }
    }
  }
};

int main(){
  vector<int> v = {INT_MIN};
  Solution s;
  cout << s.findPeakElement(v) << endl;
  return 0;
}
