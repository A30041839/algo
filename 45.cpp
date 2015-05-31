#include "leetcode.h"

using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int res = 0, cur = 0, last = 0;
    for (int i = 0; i < n; ++i){
      if (i > last){
        last = cur;
        res++;
      }
      cur = max(cur, i + nums[i]);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {2,3,1,1,4};
  cout << s.jump(nums) << endl;
  return 0;
}
