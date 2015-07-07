#include "leetcode.h"

using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    return largestNumber1(nums);
  }

  string largestNumber1(vector<int> &nums) {
    int n = nums.size(), i;
    string res;
    sort(nums.begin(), nums.end(), [](const int& lhs, const int& rhs) {
      string sa = to_string(lhs);
      string sb = to_string(rhs);
      return sa + sb > sb + sa;
      });
    for (i = 0; i < n; ++i) {
      if (nums[i] != 0) {
        break;
      }
    }
    while (i < n) {
      res.append(to_string(nums[i++]));
    }
    return res.empty() ? "0" : res;
  }
};

int main(){
  Solution s;
  vector<int> num = {21, 215};
  //vector<int> num = {121,12};
  cout << s.largestNumber(num) << endl;
  return 0;
}
