class Solution {
public:
  int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }
    int res = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= n - 3; ++i) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum >= target) {
          k--;
        }else {
          res += (k - j);
          j++;
        }
      }
    }
    return res;
  }
};
