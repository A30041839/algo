#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    return findMissingRanges1(nums, lower, upper);
  }

  vector<string> findMissingRanges1(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    int n = nums.size();
    nums.insert(nums.begin(), lower - 1);
    nums.push_back(upper + 1);
    for (int i = 1; i <= n + 1; ++i) {
      if (nums[i] - nums[i - 1] > 1) {
        res.push_back(get_range(nums[i - 1] + 1, nums[i] - 1));
      }
    }
    return res;
  }

  string get_range(int low, int high) {
    char tmp[10];
    if (low == high) {
      sprintf(tmp, "%d", low);
    } else {
      sprintf(tmp, "%d->%d", low, high);
    }
    return string(tmp);
  }
};

int main(){
  Solution s;
  vector<int> nums = {};
  vector<string> res = s.findMissingRanges(nums, 1, 80);
  print_vec<string>(res);
  return 0;
}
