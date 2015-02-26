#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    vector<int> nums = numbers;
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size() - 1 and numbers[i] <= target / 2; ++i){
      int pos = find(numbers, target - numbers[i], i + 1, numbers.size() - 1);
      if (pos != -1){
        getIndex(nums, res, numbers[i], numbers[pos]);
        return res;
      }
    }
    return res;
  }

  int find(vector<int>& numbers, int num, int low, int high){
    while (low <= high){
      int mid = (low + high) / 2;
      if (numbers[mid] == num){
        return mid;
      }else if (num < numbers[mid]){
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }
    return -1;
  }

  void getIndex(vector<int>& nums, vector<int>& res, int a, int b){
    for (int i = 0; i < nums.size(); ++i){
      if (nums[i] == a or nums[i] == b){
        res.push_back(i + 1);
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
