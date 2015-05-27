#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    return twoSum2(numbers, target);
  }

  /* use hash table, time complexity is O(n), space complexity is O(n) */
  vector<int> twoSum1(vector<int> &numbers, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < numbers.size(); ++i) {
      if (mp.count(target - numbers[i])) {
        return {mp[target - numbers[i]], i + 1};
      }else {
        mp[numbers[i]] = i + 1;
      }
    }
  }

  /* two pointers, use lambda expression to sort index of array
   * time complexity is O(nlogn), space complexity is O(n)
   */
  vector<int> twoSum2(vector<int> &numbers, int target) {
    int n = numbers.size();
    vector<int> id(n, 0);
    for (int i = 0; i < n; ++i) {
      id[i] = i;
    }
    sort(begin(id), end(id),
      [&numbers] (const int& a, const int& b) {return numbers[a] < numbers[b];});
    int i = 0, j = n - 1;
    while (i < j) {
      int sum = numbers[id[i]] + numbers[id[j]];
      if (sum == target) {
        return {min(id[i], id[j]) + 1, max(id[i], id[j]) + 1};
      }else {
        sum > target ? j-- : i++;
      }
    }
  }
};

int main(){
  int arr[4] = {0, 4, 4, 0};
  vector<int> numbers(arr, arr+ 4);
  Solution s;
  vector<int> res = s.twoSum(numbers, 0);
  cout << res[0] << "," << res[1] << endl;
  return 0;
}
