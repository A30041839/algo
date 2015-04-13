#include "leetcode.h"

using namespace std;

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (A[mid] == target) {
        return mid;
      }else if (A[mid] < target) {
        low = mid + 1;
      }else {
        high = mid - 1;
      }
    }
    return low;
  }
};

int main(){
  Solution s;
  int A[1] = {1};
  cout << s.searchInsert(A, 1, 2) << endl;
  return 0;
}
