#include "leetcode.h"

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i){
      nums[i] ^= nums[i - 1];
    }
    return nums[n - 1];
  }
};

int main(){
  vector<int> nums = {1, 5, 2, 4, 1, 4, 6, 2, 5, 8, 8};
  Solution s;
  cout << s.singleNumber(nums) << endl;
  return 0;
}
