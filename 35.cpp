#include "leetcode.h"

using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      }else if (nums[mid] < target) {
        low = mid + 1;
      }else {
        high = mid - 1;
      }
    }
    return low;
  }
};

int main(){
  Solution s;
  vector<int> A = {1};
  cout << s.searchInsert(A, 1) << endl;
  return 0;
}
