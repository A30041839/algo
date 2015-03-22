#include "leetcode.h"

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    return largestRectangleArea2(height);
  }

  int largestRectangleArea2(vector<int>& height) {
    int res = INT_MIN;
    if (height.empty()) {
      return 0;
    }
    height.push_back(-1);
    vector<int> s;
    vector<int> width;
    for (int i = 0; i < height.size(); ++i) {
      int h = height[i];
      if (s.empty() or h >= s.back()) {
        s.push_back(h);
        width.push_back(1);
      }else {
        int w = 0;
        int min_h = INT_MAX;
        while (!s.empty() and h < s.back()) {
          w += width.back();
          min_h = min(min_h, s.back());
          width.pop_back();
          s.pop_back();
          res = max(res, w * min_h);
        }
        s.push_back(h);
        width.push_back(w + 1);
      }
    }
    return res;
  }

  int largestRectangleArea1(vector<int>& height) {
    int maxArea = 0;
    for (int i = 0; i < height.size(); ++i) {
      if (i < height.size() - 1 and height[i] <= height[i + 1]) {
        continue;
      }
      int min_h = height[i];
      for (int j = i; j >= 0; --j) {
        min_h = min(min_h, height[j]);
        maxArea = max(maxArea, min_h * (i - j + 1));
      }
    }
    return maxArea;
  }
};

int main(){
  Solution s;
  vector<int> height = {0};
  cout << s.largestRectangleArea(height) << endl;
  return 0;
}
