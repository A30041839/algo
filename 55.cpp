#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool canJump(int A[], int n) {
    return canJump1(A, n);
  }

  bool canJump1(int A[], int n) {
    int max_pos = 0;
    for (int i = 0; i <= n - 1; ++i){
      if (i <= max_pos){
        max_pos = max(max_pos, i + A[i]);
        if (max_pos >= n - 1){
          return true;
        }
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  int A[3] = {2, 0, 0};
  int B[5] = {3, 2, 1, 0, 4};
  if (s.canJump(B, 5)){
    cout << "can jump" << endl;
  }else{
    cout << "can't jump" << endl;
  }
  return 0;
}
