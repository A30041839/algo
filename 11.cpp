#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    return maxArea1(height);
  }

  int maxArea1(vector<int> &height){
    int res = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
      int& min_i = height[l] < height[r] ? l : r;
      int min_h = height[min_i];
      res = max(res, min_h * (r - l));
      while (l < r and height[min_i] <= min_h) {
        min_i == l ? min_i++ : min_i--;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> height = {1, 1};
  cout << s.maxArea(height) << endl;
  return 0;
}
