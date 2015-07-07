#include "leetcode.h"

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }else {
      return convert1(s, numRows);
    }
  }

  string convert1(string s, int numRows) {
    string res;
    int gap = 2 * numRows - 2;
    int n = s.size();
    for (int i = 0; i < numRows; ++i) {
      for (int j = i; j < n; j += gap) {
        res.push_back(s[j]);
        if (i > 0 and i < numRows - 1 and j + gap - 2 * i < n) {
          res.push_back(s[j + gap - 2 * i]);
        }
      }
    }
    return res;
  }

  string convert2(string s, int numRows) {
    string res;
    int gap = 2 * numRows - 2;
    int n = s.size();
    for (int i = 0; i < numRows; ++i) {
      if (i == 0 or i == numRows - 1) {
        int k = i;
        while (k < n) {
          res.push_back(s[k]);
          k += gap;
        }
      }else {
        int a = i, b = gap - i;
        bool f = true;
        while (a < n or b < n) {
          if (f) {
            res.push_back(s[a]);
            a += gap;
          }else {
            res.push_back(s[b]);
            b += gap;
          }
          f = !f;
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.convert("PAYPALISHIRING", 15) << endl;
  cout << s.convert("AB", 3) << endl;
  cout << s.convert("PAYPALISHIRING", 3) << endl;
  return 0;
}
