#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    return twoSum3(numbers, target);
  }

  /*use binary search, time complexity: O(nlogn), space complexity: O(n)*/
  vector<int> twoSum1(vector<int> &numbers, int target) {
    vector<int> res;
    vector<int> numbers1 = numbers;
    sort(numbers.begin(), numbers.end());
    int len = (int)numbers.size();
    for (int i = 0; i < len; ++i) {
      int num1 = numbers[i];
      int num2 = target - num1;
      if (_find(numbers, num2, i + 1, len - 1) != -1) {
        res = _get_index(numbers1, num1, num2);
        return res;
      }
    }
    return res;
  }

  int _find(vector<int>& numbers, int val, int low, int high) {
    while (low <= high) {
      int mid = (low + high) / 2;
      if (numbers[mid] == val) {
        return mid;
      }else if (numbers[mid] > val) {
        high = mid - 1;
      }else {
        low = mid + 1;
      }
    }
    return -1;
  }

  vector<int> _get_index(vector<int>& numbers, int num1, int num2) {
    vector<int> res;
    for (int i = 0; i < numbers.size(); ++i) {
      if (numbers[i] == num1 or numbers[i] == num2) {
        res.push_back(i + 1);
      }
    }
    return res;
  }

  /* use hash table, time complexity is O(n), space complexity is O(n) */
  vector<int> twoSum2(vector<int> &numbers, int target) {
    unordered_map<int, int> mp;
    int len = (int)numbers.size();
    for (int i = 0; i < len; ++i) {
      if (mp.count(target - numbers[i])) {
        vector<int> res = {mp[target - numbers[i]], i + 1};
        return res;
      }else {
        mp[numbers[i]] = i + 1;
      }
    }
  }

  /* two pointers, use lambda expression to sort index of array
   * time complexity is O(nlogn), space complexity is O(n)
   */
  vector<int> twoSum3(vector<int> &numbers, int target) {
    int n = (int)numbers.size();
    vector<int> id(n, 0);
    for (int i = 0; i < n; ++i) {
      id[i] = i;
    }
    sort(begin(id), end(id),
      [&numbers](const int& a, const int& b) {return numbers[a] < numbers[b];});
    int start = 0, end = n - 1;
    while (start < end) {
      int sum = numbers[id[start]] + numbers[id[end]];
      if (sum == target) {
        return {min(id[start], id[end]) + 1, max(id[start], id[end]) + 1};
      }else {
        sum > target ? end-- : start++;
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
