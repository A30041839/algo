#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    return containsNearbyDuplicate1(nums, k);
  }

  bool containsNearbyDuplicate1(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      if (mp.find(nums[i]) != mp.end()) {
        if (i - mp[nums[i]] <= k) {
          return true;
        }
      }
      mp[nums[i]] = i;
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1,2,5,1,6,9,1};
  if (s.containsNearbyDuplicate(nums, 1)) {
    cout << "true" << endl;
  }
  return 0;
}
