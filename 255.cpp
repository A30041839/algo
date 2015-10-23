#include "leetcode.h"

using namespace std;

class Solution {
  struct range {
    range(int _val, int _start, int _end): val(_val), start(_start), end(_end) {}
    int val;
    int start;
    int end;
  };

public:
  bool verifyPreorder(vector<int>& preorder) {
    return verify1(preorder);
  }

  //TLE
  bool verify(vector<int>& preorder, int low, int high) {
    if (low >= high) {
      return true;
    }
    int pos = -1;
    for (int i = low + 1; i <= high; ++i) {
      if (preorder[i] > preorder[low]) {
        if (pos == -1) {
          pos = i;
        }
      }else {
        if (pos != -1) {
          return false;
        }
      }
    }
    if (pos == -1 or pos == low + 1) {
      return verify(preorder, low + 1, high);
    }else {
      return verify(preorder, low + 1, pos - 1) and verify(preorder, pos, high);
    }
  }

  bool verify1(vector<int>& preorder) {
    vector<range> v;
    int n = preorder.size();
    for (int i = 0; i < n; ++i) {
      if (v.empty()) {
        v.push_back(range(preorder[i], INT_MIN, INT_MAX));
      }else if (preorder[i] > preorder[i - 1]) {
        while (preorder[i] > v.back().end) {
          v.pop_back();
        }
        v.push_back(range(preorder[i], v.back().val + 1, v.back().end));
      }else {
        if (preorder[i] < v.back().start) {
          return false;
        }
        v.push_back(range(preorder[i], v.back().start, v.back().val - 1));
      }
    }
    return true;
  }
};
