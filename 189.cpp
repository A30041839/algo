#include "leetcode.h"

using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1){
      return;
    }
    rotate4(nums, n, k);
  }

  //trivial solution1
  void rotate1(vector<int>& nums, int n, int k) {
    k = k % n;
    vector<int> tmp;
    for (int i = k; i > 0; --i){
      tmp.push_back(nums[n - i]);
    }
    for (int i = n - k - 1; i >= 0; --i){
      nums[i + k] = nums[i];
    }
    for (int i = 0; i < k; ++i){
      nums[i] = tmp[i];
    }
  }

  //trivial solution2
  void rotate2(vector<int>& nums, int n, int k) {
    vector<int> tmp(n, 0);
    for (int i = 0; i < n; ++i){
      tmp[(i + k) % n] = nums[i];
    }
    for (int i = 0; i < n; ++i){
      nums[i] = tmp[i];
    }
  }

  //in-place algorithm, use only O(1) space
  void rotate3(vector<int>& nums, int n, int k) {
    int cnt = 0;
    int start = 0;
    while (cnt != n) {
      cnt += _rotate3_helper(nums, n, k, start++);
    }
  }

  int _rotate3_helper(vector<int>& nums, int n, int k, int start) {
    int tmp1 = nums[start];
    int i = (start + k) % n;
    int cnt = 0;
    while (i != start) {
      int tmp2 = nums[i];
      nums[i] = tmp1;
      tmp1 = tmp2;
      i = (i + k) % n;
      cnt++;
    }
    nums[start] = tmp1;
    return ++cnt;
  }

  void rotate4(vector<int>& nums, int n, int k) {
    k %= n;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
  }
};

int main(){
  Solution s;
  vector<int> nums = {1,2,3,4,5};
  s.rotate(nums,10);
  print_vec(nums);
  return 0;
}
