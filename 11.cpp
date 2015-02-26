#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    return maxArea1(height);
  }

  int maxArea1(vector<int> &height){
    int res = INT_MIN;
    int l = 0, r = height.size() - 1;
    while (l < r){
      int h_min = min(height[l], height[r]);
      res = max(res, h_min * (r - l));
      if (height[l] < height[r]){
        while (l < r and height[l] <= h_min){
          l++;
        }
      }else{
        while (l < r and height[r] <= h_min){
          r--;
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> height = {1, 2, 3};
  cout << s.maxArea(height) << endl;
  return 0;
}
