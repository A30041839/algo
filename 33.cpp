#include "leetcode.h"

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    return search1(nums, target);
  }

  int search1(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      }else if (nums[low] > nums[mid]) {
        if (nums[mid] < target and target <= nums[high]) {
          low = mid + 1;
        }else {
          high = mid - 1;
        }
      }else {
        if (nums[low] <= target and target < nums[mid]) {
          high = mid - 1;
        }else {
          low = mid + 1;
        }
      }
    }
    return -1;
  }
};

int main(){
  Solution s;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
  cout << s.search(nums, 4) << endl;
  cout << s.search(nums, 0) << endl;
  cout << s.search(nums, 3) << endl;
  cout << s.search(nums, 2) << endl;
  return 0;
}
