#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    return containsDuplicate2(nums);
  }

  bool containsDuplicate1(vector<int>& nums) {
    unordered_set<int> s;
    for (int x : nums) {
      if (s.find(x) != s.end()) {
        return true;
      }
      s.insert(x);
    }
    return false;
  }

  bool containsDuplicate2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1};
  if (s.containsDuplicate(nums)) {
    cout << "true" << endl;
  }
  return 0;
}
