#include "leetcode.h"

using namespace std;

class Solution {
private:
  string getRange(int a, int b) {
    if (a == b) {
      return to_string(a);
    }else {
      return to_string(a) + "->" + to_string(b);
    }
  }

public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    int n = nums.size();
    vector<string> res;
    for (int i = 0; i < n; ++i) {
      int s = i;
      while (i < n - 1 and nums[i] + 1 == nums[i + 1]) {
        i++;
      }
      res.push_back(getRange(nums[s], nums[i]));
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {-1,0,1,5,9,10,11,15,16};
  auto res = s.summaryRanges(nums);
  print_vec(res);
  return 0;
}
