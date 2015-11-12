#include "leetcode.h"
using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    if (denominator == 0) return "";
    int sgn = 1;
    if ((numerator < 0 and denominator > 0) or (numerator > 0 and denominator < 0)) sgn = -1;
    long _num = abs((long)numerator);
    long _den = abs((long)denominator);
    long intPart = _num / _den;
    _num %= _den;
    string _intPart = sgn == 1 ? to_string(intPart) : "-" + to_string(intPart);
    if (_num == 0) return _intPart;
    unordered_map<int, int> mp;
    string frac_part;
    while (_num > 0 and mp.find(_num) == mp.end()) {
      mp[_num] = (int)frac_part.size();
      frac_part.push_back(_num * 10 / _den + '0');
      _num = _num * 10 % _den;
    }
    if (_num == 0) {
      return _intPart + "." + frac_part;
    }else {
      frac_part.insert(frac_part.begin() + mp[_num], '(');
      frac_part.push_back(')');
      return _intPart + "." + frac_part;
    }
  }
};

int main(){
  Solution s;
  vector<int> numerators = {-1, -1, 1, INT_MIN, 0, 2, 1};
  vector<int> denominators = {-2147483648, 6, 214748364, -1, 10, 2, 2};
  for (int i = 0; i < numerators.size(); ++i){
    cout << s.fractionToDecimal(numerators[i], denominators[i]) << endl;
  }
  return 0;
}
