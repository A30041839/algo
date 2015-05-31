#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    return canJump1(nums);
  }

  bool canJump1(vector<int>& nums) {
    int max_pos = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i){
      if (i <= max_pos){
        max_pos = max(max_pos, i + nums[i]);
        if (max_pos >= n - 1){
          return true;
        }
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  vector<int> A = {2, 0, 0};
  if (s.canJump(A)){
    cout << "can jump" << endl;
  }else{
    cout << "can't jump" << endl;
  }
  return 0;
}
