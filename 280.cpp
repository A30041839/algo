class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    if (nums.size() < 2) {
      return;
    }
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if ((nums[i] >= nums[i - 1]) ^ (i & 1)) {
        swap(nums[i], nums[i - 1]);
      }
    }
  }
};
