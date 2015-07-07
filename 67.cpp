#include "leetcode.h"

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int la = a.size(), lb = b.size();
    string res;
    int carry = 0, sum = 0, d1, d2;
    for (int i = la - 1, j = lb - 1; i >= 0 or j >= 0 or carry; --i, --j) {
      d1 = i >= 0 ? a[i] - '0' : 0;
      d2 = j >= 0 ? b[j] - '0' : 0;
      sum = d1 + d2 + carry;
      carry = sum / 2;
      sum %= 2;
      res.push_back(sum + '0');
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
