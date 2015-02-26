#include "leetcode.h"

using namespace std;

class Solution {
public:
  int findMin(vector<int> &num) {
    return findMin1(num);
  }

  int findMin1(vector<int>& num){
    int low = 0, high = num.size() - 1;
    while (low <= high){
      int mid = (low + high) / 2;
      if (num[low] <= num[high]){
        return num[low];
      }else if (num[low] > num[mid]){
        high = mid;
      }else{
        low = mid + 1;
      }
    }
  }
};

int main(){
  Solution s;
  vector<int> v = {8, 0};
  cout << s.findMin(v) << endl;
  return 0;
}
