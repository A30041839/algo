#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> searchRange(int A[], int n, int target) {
    vector<int> res(2, -1);
    int pos1 = firstLarger(A, n, target - 1);
    int pos2 = firstLarger(A, n, target);
    if (pos1 != pos2){
      res[0] = pos1;
      res[1] = pos2 - 1;
    }
    return res;
  }

  int firstLarger(int A[], int n, int val){
    int low = 0, high = n - 1;
    while (low <= high){
      int mid = (low + high) / 2;
      if (A[mid] <= val){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
    return low;
  }
};

int main(){
  int A[1] = {7};
  Solution s;
  vector<int> res = s.searchRange(A, 1, 7);
  cout << res[0] << "," << res[1] << endl;
  return 0;
}
