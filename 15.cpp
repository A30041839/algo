#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > res;
    int len = num.size();
    if (len < 3) {
      return res;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < len - 2; ++i) {
      if (i == 0 || num[i] > num[i - 1]) {
        //remove duplicate
        int x = -1 * num[i];
        int start = i + 1;
        int end = len - 1;
        while (start < end) {
          if (num[start] + num[end] == x) {
            vector<int> sol = {num[i], num[start], num[end]};
            res.push_back(sol);
            start++;
            end--;
            while (start < end and num[start] == num[start - 1]) {
              start++;
            }
            while (start < end and num[end] == num[end + 1]) {
              end--;
            }
          }else if (num[start] + num[end] > x) {
            end--;
          }else {
            start++;
          }
        }
      }
    }
    return res;
  }

};

int main(){
  Solution s;
  int A[6] = {-1,0,1,2,-1,-4};
  vector<int> num(A, A + 6);
  for (auto& sol : s.threeSum(num)) {
    for (int x : sol) {
      cout << x << ",";
    }
    cout << endl;
  }
  return 0;
}
