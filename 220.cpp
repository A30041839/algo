#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    return solve1(nums, k, t);
  }

  bool solve1(vector<int>& nums, int k, int t) {
    multimap<long, int> mp; //avoid overflow
    for (int i = 0; i < nums.size(); ++i) {
      mp.insert({nums[i], i});
    }
    auto iter = mp.begin();
    while (iter != mp.end()) {
      auto it = iter;
      it++;
      while (it != mp.end() and (it->first - iter->first <= t)) {
        if (abs(it->second - iter->second) <= k) {
          return true;
        }
        it++;
      }
      iter++;
    }
    return false;
  }
};

int main() {
  return 0;
}
