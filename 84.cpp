#include "leetcode.h"

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    return largestRectangleArea3(height);
  }

  int largestRectangleArea1(vector<int>& height) {
    int res = 0;
    vector<int> width, hgt;
    height.push_back(-1);
    int n = height.size();
    for (int i = 0; i < n; ++i) {
      if (hgt.empty() or height[i] >= hgt.back()) {
        hgt.push_back(height[i]);
        width.push_back(1);
      }else {
        int new_height = 0, new_width = 0;
        while (!hgt.empty() and hgt.back() >= height[i]) {
          new_height = hgt.back();
          new_width += width.back();
          res = max(res, new_height * new_width);
          hgt.pop_back();
          width.pop_back();
        }
        new_height = height[i];
        new_width += 1;
        hgt.push_back(new_height);
        width.push_back(new_width);
      }
    }
    return res;
  }

  int largestRectangleArea2(vector<int>& height) {
    int res = 0;
    int n = height.size();
    for (int i = 0; i < n; ++i) {
      if (i < n - 1 and height[i] <= height[i + 1]) {
        continue;
      }
      int min_h = height[i];
      for (int j = i; j >= 0; --j) {
        min_h = min(min_h, height[j]);
        res = max(res, min_h * (i - j + 1));
      }
    }
    return res;
  }

  int largestRectangleArea3(vector<int>& height) {
    height.push_back(0);
    int n = height.size(), res = 0;
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (s.empty() or height[i] >= height[s.back()]) {
        s.push_back(i);
      }else {
        int h = height[s.back()];
        s.pop_back();
        res = max(res, h * (s.empty() ? i : (i - s.back() - 1)));
        --i;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> height = {3,1,3,2,2};
  cout << s.largestRectangleArea(height) << endl;
  return 0;
}
