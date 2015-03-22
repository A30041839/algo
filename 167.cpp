#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
      int j = binary_search(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
      if (j != -1) {
        return {i + 1, j + 1};
      }
    }
  }

  int binary_search(vector<int> &numbers, int low, int high, int target) {
    while (low <= high) {
      int mid = (low + high) / 2;
      if (numbers[mid] > target) {
        high = mid - 1;
      }else if (numbers[mid] < target) {
        low = mid + 1;
      }else {
        return mid;
      }
    }
    return -1;
  }
};

int main(){
  Solution s;
  vector<int> numbers = {2, 7, 11, 15};
  vector<int> res = s.twoSum(numbers, 9);
  cout << res[0] << "," << res[1] << endl;
  return 0;
}
