#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> res;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
      int tmp = digits[i] + carry;
      carry = tmp >= 10 ? 1 : 0;
      tmp = tmp >= 10 ? tmp % 10 : tmp;
      res.push_back(tmp);
    }
    if (carry == 1) {
      res.push_back(1);
    }
    reverse(res.begin(), res.end());
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
