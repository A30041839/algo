#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    return maxSlidingWindow2(nums, k);
  }

  vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
    auto cmp = [&nums](int i, int j) { return nums[i] < nums[j]; };
    priority_queue<int, vector<int>, decltype(cmp)> max_pq(cmp);
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      max_pq.push(i);
      if (i >= k - 1) {
        int j = max_pq.top();
        while (j < i - k + 1) {
          max_pq.pop();
          j = max_pq.top();
        }
        res.push_back(nums[j]);
      }
    }
    return res;
  }

  vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> dq;
    int curmax = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      if (i < k) {
        curmax = max(curmax, nums[i]);
        dq.push_back(nums[i]);
        if (i == k - 1) {
          res.push_back(curmax);
        }
      }else {
        if (dq.size() == k) {
          dq.pop_front();
        }
        dq.push_back(nums[i]);
        curmax = INT_MIN;
        int n = dq.size();
        while (n--) {
          curmax = max(curmax, dq.front());
          dq.push_back(dq.front());
          dq.pop_front();
        }
        while (dq.front() < curmax) {
          dq.pop_front();
        }
        res.push_back(curmax);
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  auto res = s.maxSlidingWindow(nums, 3);
  print_vec(res);
  return 0;
}
