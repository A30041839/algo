#include "leetcode.h"

using namespace std;

class Solution {
public:
  //O(n) solution, similar with partition algorithm
  //in quick sort.
  int removeElement(vector<int>& nums, int val) {
    int i = -1;
    int n = nums.size();
    for (int j = 0; j < n; ++j){
      if (nums[j] != val){
        swap(nums[++i], nums[j]);
      }
    }
    return i + 1;
  }
};

int main(){
  Solution s;
  vector<int> nums = {1, 1, 1, 1, 1, 2};
  int len = s.removeElement(nums, 1);
  print_vec(nums);
  return 0;
}
