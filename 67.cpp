#include "leetcode.h"

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    if (len_a == 0){
      return b;
    }
    if (len_b == 0){
      return a;
    }
    string res;
    int carry = 0;
    for (int i = len_a - 1, j = len_b - 1; i >=  0 or j >= 0; --i, --j){
      int c1 = i >= 0 ? a[i] - '0' : 0;
      int c2 = j >= 0 ? b[j] - '0' : 0;
      int sum = c1 + c2 + carry;
      carry = sum >= 2 ? 1 : 0;
      sum %= 2;
      res.push_back(sum + '0');
    }
    if (carry == 1){
      res.push_back('1');
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(){
  Solution s;
  string a = "11";
  string b = "1";
  cout << s.addBinary(a, b) << endl;
  return 0;
}
