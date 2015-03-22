#include "leetcode.h"

using namespace std;

class Solution {
public:
  void rotate(int nums[], int n, int k) {
    if (n < 1){
      return;
    }
    rotate1(nums, n, k);
  }

  void rotate1(int nums[], int n, int k) {
    k = k % n;
    vector<int> tmp;
    for (int i = k; i > 0; --i){
      tmp.push_back(nums[n - i]);
    }
    for (int i = n - k - 1; i >= 0; --i){
      nums[i + k] = nums[i];
    }
    for (int i = 0; i < k; ++i){
      nums[i] = tmp[i];
    }
  }

  void rotate2(int nums[], int n, int k) {
    vector<int> tmp(n, 0);
    for (int i = 0; i < n; ++i){
      tmp[(i + k) % n] = nums[i];
    }
    for (int i = 0; i < n; ++i){
      nums[i] = tmp[i];
    }
  }
};

void print_arr(int nums[], int n){
  for (int i = 0; i < n; ++i){
    cout << nums[i] << ",";
  }
  cout << endl;
}

int main(){
  Solution s;
  int nums[] = {1,2,3,4,5,6};
  s.rotate(nums,6,2);
  print_arr(nums, 6);
  return 0;
}
