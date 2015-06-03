#include "leetcode.h"

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    return findMin1(nums);
  }

  int findMin1(vector<int> &nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      //the only difference with non-duplicate scenario
      while (low < high and nums[low] == nums[high]) {
        low++;
      }
      int mid = (low + high) / 2;
      if (nums[low] <= nums[high]) {
        return nums[low];
      }else if (nums[low] > nums[mid]) {
        high = mid;
      }else {
        low = mid + 1;
      }
    }
  }
};

int main(){
  Solution s;
  vector<int> num = {2,3,1};
  cout << s.findMin(num) << endl;
  return 0;
}
