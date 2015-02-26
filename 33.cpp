#include "leetcode.h"

using namespace std;

class Solution {
public:
  int search(int A[], int n, int target) {
    return search1(A, n, target);
  }
};

int main(){
  Solution s;
  int A[8] = {4, 5, 6, 7, 0, 1, 2, 3};
  cout << s.search(A, 8, -1) << endl;
  cout << s.search(A, 8, 8) << endl;
  return 0;
}
