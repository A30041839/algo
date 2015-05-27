#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    return searchRange3(nums, target);
  }

  vector<int> searchRange1(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int pos1 = lower_bound(nums, target);
    int pos2 = lower_bound(nums, target + 1);
    if (pos1 != pos2) {
      res[0] = pos1;
      res[1] = pos2 - 1;
    }
    return res;
  }

  vector<int> searchRange2(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int pos1 = upper_bound(nums, target - 1);
    int pos2 = upper_bound(nums, target);
    if (pos1 != pos2){
      res[0] = pos1;
      res[1] = pos2 - 1;
    }
    return res;
  }

  vector<int> searchRange3(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int pos1 = lower_bound(nums, target);
    int pos2 = upper_bound(nums, target);
    if (pos1 != pos2) {
      res[0] = pos1;
      res[1] = pos2 - 1;
    }
    return res;
  }

  //return the first i that A[i] > val
  int upper_bound(vector<int>& nums, int val){
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) >> 1;
      if (nums[mid] <= val) {
        low = mid + 1;
      }else {
        high = mid - 1;
      }
    }
    return low;
  }

  //return the first i that A[i] >= val
  int lower_bound(vector<int>& nums, int val) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) >> 1;
      if (nums[mid] >= val) {
        high = mid - 1;
      }else {
        low = mid + 1;
      }
    }
    return low;
  }
};

int main(){
  vector<int> nums = {7};
  Solution s;
  vector<int> res = s.searchRange(nums, 7);
  cout << res[0] << "," << res[1] << endl;
  return 0;
}
