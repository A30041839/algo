#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    vector<int> res(n, 0);
    int carry = 1;
    for (int i = n - 1; i >= 0; --i) {
      int sum = digits[i] + carry;
      carry = sum / 10;
      sum %= 10;
      res[i] = sum;
    }
    if (carry == 1) {
      res.insert(res.begin(), 1);
    }
    return res;
  }
};

int main(){
  vector<int> digits = {9, 9, 9};
  Solution s;
  vector<int> sum = s.plusOne(digits);
  for (int a : sum){
    cout << a << ",";
  }
  cout << endl;
  return 0;
}
