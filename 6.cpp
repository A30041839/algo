#include "leetcode.h"

using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows == 1 or nRows >= s.length() or s.length() == 0){
      return s;
    }
    string res;
    int len = s.length();
    int k = 2 * nRows - 2;
    for (int i = 0; i < nRows; ++i){
      int gap = i * 2;
      for (int j = i; j < len; j += gap){
        res.push_back(s[j]);
        gap = k - gap;
        gap = gap == 0 ? k - gap : gap;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.convert("PAYPALISHIRING", 15) << endl;
  cout << s.convert("PAYPALISHIRING", 4) << endl;
  return 0;
}
