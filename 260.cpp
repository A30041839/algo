class Solution {
public:
  //find the first different bit of the two numbers, partition the
  //nums into two groups at this bit, then in each group, find the single
  //number
  vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      tmp ^= nums[i];
    }
    int pos = 0;
    while ((tmp & 1) == 0) {
      tmp >>= 1;
      pos++;
    }
    int mask = 1 << pos;
    vector<int> ones, zeros;
    for (int i = 0; i < n; ++i) {
      if (nums[i] & mask) {
        ones.push_back(nums[i]);
      }else {
        zeros.push_back(nums[i]);
      }
    }
    int a = 0, b = 0;
    for (int i = 0; i < ones.size(); ++i) {
      a ^= ones[i];
    }
    for (int i = 0; i < zeros.size(); ++i) {
      b ^= zeros[i];
    }
    return {a, b};
  }
};
