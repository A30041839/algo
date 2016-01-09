class NumArray {
  vector<int> leftsum;
public:
  NumArray(vector<int> &nums) {
    int n = nums.size();
    leftsum.assign(n, 0);
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      tmp += nums[i];
      leftsum[i] = tmp;
    }
  }

  int sumRange(int i, int j) {
    if (i == 0) {
      return leftsum[j];
    }else {
      return leftsum[j] - leftsum[i - 1];
    }
  }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
