#include "leetcode.h"

using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    sortColors2(nums);
  }

  void sortColors1(vector<int>& nums) {
    int n = nums.size();
    int b[3] = {0, 0, 0};
    for (int i = 0; i < n; ++i){
      b[nums[i]]++;
    }
    int k = 0;
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < b[i]; ++j){
        nums[k++] = i;
      }
    }
  }

  void sortColors2(vector<int>& nums) {
    int i = 0, zero = 0, two = nums.size() - 1;
    while (i <= two) {
      if (nums[i] == 0) {
        swap(nums[i++], nums[zero++]);
      }else if (nums[i] == 2) {
        swap(nums[i], nums[two--]);
      }else {
        i++;
      }
    }
  }
};

int main(){
  vector<int> A = {1, 0, 2, 1};
  Solution s;
  s.sortColors(A);
  for (int i = 0; i < A.size(); ++i){
    cout << A[i] << ",";
  }
  cout << endl;
  return 0;
}
