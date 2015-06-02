#include "leetcode.h"

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    nextPermutation1(nums);
  }

  void nextPermutation1(vector<int> &nums) {
    if (nums.empty()) {
      return;
    }
    int pos1 = -1, pos2 = 0;
    int n = nums.size();
    for (int i = n - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        pos1 = i - 1;
        break;
      }
    }
    if (pos1 == -1) {
      sort(nums.begin(), nums.end());
      return;
    }
    for (int i = n - 1; i > 0; --i) {
      if (nums[i] > nums[pos1]) {
        pos2 = i;
        break;
      }
    }
    swap(nums[pos1], nums[pos2]);
    reverse(nums.begin() + pos1 + 1, nums.end());
  }
};

int main(){
  Solution s;
  //vector<int> v = {5, 4, 1, 3, 2};
  //vector<int> v = {5, 4, 3, 2, 1};
  vector<int> v = {1,5,1};
  s.nextPermutation(v);
  for (int i = 0; i < v.size(); ++i){
    cout << v[i] << ",";
  }
  cout << endl;
  return 0;
}
