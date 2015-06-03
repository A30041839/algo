#include "leetcode.h"

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    return findMin1(nums);
  }

  int findMin1(vector<int>& nums){
    int low = 0, high = nums.size() - 1;
    while (low <= high){
      int mid = (low + high) / 2;
      if (nums[low] <= nums[high]){
        return nums[low];
      }else if (nums[low] > nums[mid]){
        high = mid;
      }else{
        low = mid + 1;
      }
    }
  }
};

int main(){
  Solution s;
  vector<int> v = {8, 0};
  cout << s.findMin(v) << endl;
  return 0;
}
