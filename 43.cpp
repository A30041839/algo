#include "leetcode.h"

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();
    int sum, carry;
    string res(n1 + n2, '0');
    for (int i = n1 - 1; i >= 0; --i) {
      carry = 0;
      for (int j = n2 - 1; j >= 0; --j) {
        sum = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1] - '0' + carry;
        carry = sum / 10;
        sum %= 10;
        res[i + j + 1] = sum + '0';
      }
      if (carry) {
        res[i] = carry + '0';
      }
    }
    while (res.size() > 1 and res[0] == '0') {
      res.erase(res.begin());
    }
    return res;
  }
};

int main(){
  Solution s;
  string a = "123";
  string b = "0";
  cout << s.multiply(a, b) << endl;
  return 0;
}
