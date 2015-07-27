#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int a, b, c1 = 0, c2 = 0;
    //find the two elements appearing the most
    for (int x : nums) {
      if (c1 > 0 and x == a) {
        c1++;
        continue;
      }
      if (c2 > 0 and x == b) {
        c2++;
        continue;
      }
      if (c1 == 0) {
        a = x;
        c1 = 1;
        continue;
      }
      if (c2 == 0) {
        b = x;
        c2 = 1;
        continue;
      }
      c1--;
      c2--;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int x : nums) {
      if (c1 > 0 and x == a) {
        cnt1++;
      }
      if (c2 > 0 and x == b) {
        cnt2++;
      }
    }
    vector<int> res;
    if (cnt1 > nums.size() / 3) {
      res.push_back(a);
    }
    if (cnt2 > nums.size() / 3) {
      res.push_back(b);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {0,-1,2,-1};
  auto res = s.majorityElement(nums);
  print_vec(res);
  return 0;
}
