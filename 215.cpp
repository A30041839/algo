#include "leetcode.h"

using namespace std;

class Solution {
private:
  int partition(vector<int>& nums, int beg, int end) {
    int mid = beg + (end - beg) / 2;
    swap(nums[mid], nums[end]);
    int i = beg, j = beg - 1;
    for (; i <= end; ++i) {
      if (nums[i] >= nums[end]) { //! only difference btw kth largest or kth smallest
        swap(nums[++j], nums[i]);
      }
    }
    return j;
  }

public:
  int findKthLargest(vector<int>& nums, int k) {
    return findKthLargest1(nums, 0, nums.size() - 1, k);
  }

  int findKthLargest1(vector<int>& nums, int beg, int end, int k) {
    int pos = partition(nums, beg, end);
    int rank = pos - beg + 1;
    if (k == rank) {
      return nums[pos];
    }else if (k < rank) {
      return findKthLargest1(nums, beg, pos - 1, k);
    }else {
      return findKthLargest1(nums, pos + 1, end, k - rank);
    }
  }

  int iterative(vector<int>& nums, int k) {
    int beg = 0, end = nums.size() - 1;
    int pos = partition(nums, beg, end);
    while (pos != k - 1) {
      if (pos < k - 1) {
        beg = pos + 1;
      }else {
        end = pos - 1;
      }
      pos = partition(nums, beg, end);
    }
    return nums[pos];
  }
};

int main() {
  Solution s;
  vector<int> nums = {3,2,1,5,6,4};
  for (int i = 1; i <= 6; ++i) {
    cout << s.findKthLargest(nums, i) << endl;
  }
  return 0;
}
