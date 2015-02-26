#include "leetcode.h"

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int l1 = num1.length();
    int l2 = num2.length();
    string res(l1 + l2, '0');
    for (int i = l2 - 1; i >= 0; --i){
      string tmp(l2 - 1 - i, '0');
      int carry = 0;
      for (int j = l1 - 1; j >= 0; --j){
        int p = (num2[i] - '0') * (num1[j] - '0') + carry;
        carry = p >= 10 ? p / 10 : 0;
        tmp.push_back(p % 10 + '0');
      }
      if (carry > 0){
        tmp.push_back(carry + '0');
      }
     res = add(res, tmp);
    }
    while (res.length() > 1 and res.back() == '0'){
      res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
  }

  string add(string a, string b){
    int carry = 0;
    string res;
    for (int i = 0; i < a.length() or i < b.length(); ++i){
      int s1 = i >= a.length() ? 0 : a[i] - '0';
      int s2 = i >= b.length() ? 0 : b[i] - '0';
      int sum = carry + s1 + s2;
      carry = sum >= 10 ? 1: 0;
      res.push_back(sum % 10 + '0');
    }
    if (carry > 0){
      res.push_back('1');
    }
    return res;
  }
};

int main(){
  Solution s;
  string a = "123";
  string b = "4567";
  cout << s.multiply(a, b) << endl;
  return 0;
}
