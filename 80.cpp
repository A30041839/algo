#include "leetcode.h"

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) {
      return n;
    }
    return removeDuplicates1(nums, n);
  }

  int removeDuplicates1(vector<int>& nums, int n) {
    int k = 2;
    for (int i = 2; i < n; ++i) {
      if (!(nums[i] == nums[k - 1] and nums[i] == nums[k - 2])) {
        nums[k++] = nums[i];
      }
    }
    return k;
  }

  int removeDuplicates2(vector<int>& nums, int n) {
    int k = 0;
    for (int s = 0, i = 0; i < n; ++i) {
      if (i == n - 1 or nums[i] != nums[i + 1]) {
        nums[k++] = nums[i];
        if (i - s >= 1) {
          nums[k++] = nums[i];
        }
        s = i + 1;
      }
    }
    return k;
  }
};

int main(){
  vector<int> a = {1,1,2,2,2,3};
  Solution s;
  int len = s.removeDuplicates(a);
  for (int i = 0; i < len; ++i) {
    cout << a[i] << ",";
  }
  cout << endl;
  return 0;
}
