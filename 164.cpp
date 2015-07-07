#include "leetcode.h"

using namespace std;

class Solution {
private:
  void radixSort(vector<int>& nums, int n) {
    vector<vector<int>> helper(2, vector<int>());
    for (int i = 0; i < 31; ++i) { //!
      for (int j = 0; j < n; ++j) {
        helper[(nums[j] >> i) & 1].push_back(nums[j]);
      }
      copy(helper[0].begin(), helper[0].end(), nums.begin());
      copy(helper[1].begin(), helper[1].end(), nums.begin() + helper[0].size());
      helper[0].clear();
      helper[1].clear();
    }
  }

public:
  int maximumGap(vector<int> &nums) {
    return maximumGap2(nums);
  }

  int maximumGap1(vector<int> &nums) {
    int n = nums.size(), res = 0;
    if (n < 2) {
      return 0;
    }
    radixSort(nums, n);
    for (int i = 1; i < n; ++i) {
      res = max(res, nums[i] - nums[i - 1]);
    }
    return res;
  }

  //Suppose there are N elements and they range from A to B.
  //Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]
  //Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)],
  //then we will have at most num = (B - A) / len + 1 of bucket
  //for any number K in the array, we can easily find out which bucket it belongs by calculating
  //loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.
  //Since the maximum difference between elements in the same buckets will be at most len - 1,
  //so the final answer will not be taken from two elements in the same buckets.
  //For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max
  //could be the potential answer to the question. Return the maximum of all those values.
  int maximumGap2(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return 0;
    }
    int minv = nums[0], maxv = nums[0];
    for (int x : nums) {
      minv = min(minv, x);
      maxv = max(maxv, x);
    }
    int len = (maxv - minv) / n + 1;
    int n_bucket = (maxv - minv) / len + 1;
    vector<int> max_bucket(n_bucket, INT_MIN), min_bucket(n_bucket, INT_MAX);
    for (int x : nums) {
      int bkt = (x - minv) / len;
      max_bucket[bkt] = max(max_bucket[bkt], x);
      min_bucket[bkt] = min(min_bucket[bkt], x);
    }
    int res = 0, prev = -1;
    for (int i = 0; i < n_bucket; ++i) {
      if (max_bucket[i] != INT_MIN) {
        if (prev != -1) {
          res = max(res, min_bucket[i] - max_bucket[prev]);
        }
        prev = i;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> num = {2,1,4,7};
  cout << s.maximumGap(num) << endl;
  return 0;
}
