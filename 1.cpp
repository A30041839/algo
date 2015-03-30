#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    return twoSum1(numbers, target);
  }

  vector<int> twoSum1(vector<int> &numbers, int target) {
    vector<int> res;
    vector<int> numbers1 = numbers;
    int len = numbers.size();
    for (int i = 0; i < len; ++i) {
      int num1 = numbers[i];
      int num2 = target - num1;
  }

  vector<int> twoSum2(vector<int> &numbers, int target) {
  }

  int find(vector<int>& numbers, int num, int low, int high) {
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
