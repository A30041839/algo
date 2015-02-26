#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i){
      digits[i] += carry;
      if (digits[i] >= 10){
        digits[i] %= 10;
        carry = 1;
      }else{
        carry = 0;
      }
    }
    if (carry == 0){
      return digits;
    }else{
      vector<int> res(digits.size() + 1, 1);
      for (int k = 1; k <= digits.size(); ++k){
        res[k] = digits[k - 1];
      }
      return res;
    }
  }
};

int main(){
  vector<int> digits = {1, 0, 1};
  Solution s;
  vector<int> sum = s.plusOne(digits);
  for (int a : sum){
    cout << a << ",";
  }
  cout << endl;
  return 0;
}
