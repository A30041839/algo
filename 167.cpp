#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    return twoSum2(numbers, target);
  }

private:
  vector<int> twoSum1(vector<int>& numbers, int target) {
    unordered_map<int, int> mp;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
      if (mp.count(target - numbers[i])) {
        return {mp[target - numbers[i]], i + 1};
      }else {
        mp[numbers[i]] = i + 1;
      }
    }
  }

  vector<int> twoSum2(vector<int>& numbers, int target) {
    int n = numbers.size();
    int beg = 0, end = n - 1;
    while (beg < end) {
      int sum = numbers[beg] + numbers[end];
      if (sum == target) {
        return {beg + 1, end + 1};
      }else {
        sum > target ? end-- : beg++;
      }
    }
  }
};

int main(){
  Solution s;
  vector<int> numbers = {2, 7, 11, 15};
  vector<int> res = s.twoSum(numbers, 9);
  cout << res[0] << "," << res[1] << endl;
  return 0;
}
