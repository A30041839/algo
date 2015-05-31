#include "leetcode.h"

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    nextPermutation1(nums);
  }

  void nextPermutation1(vector<int> &nums) {
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
