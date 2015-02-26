#include "leetcode.h"

using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    return fractionToDecimal1(numerator, denominator);
  }

  string fractionToDecimal1(int numerator, int denominator){
    string res;
    int res_sgn = sgn(numerator) * sgn(denominator);
    long _numerator = abs((long)numerator);
    long _denominator = abs((long)denominator);
    long i = _numerator / _denominator;
    do {
      res.push_back(i % 10 + '0');
      i /= 10;
    } while (i > 0);
    if (res_sgn == -1 and _numerator != 0){
      res.push_back('-');
    }
    reverse(res.begin(), res.end());
    string decimal;
    unordered_map<long, int> remains;
    long r = _numerator % _denominator;

    int k = 0;
    while (r != 0 and remains.count(r) == 0){
      remains.insert({r, k++});
      r *= 10;
      decimal.push_back(r / _denominator + '0');
      r %= _denominator;
    }
    if (!decimal.empty()){
      res.push_back('.');
      if (r == 0){
        res.append(decimal);
      }else{
        decimal.insert(remains[r], "(");
        decimal.push_back(')');
        res.append(decimal);
      }
    }
    return res;
  }

  int sgn(int num){
    return num >= 0 ? 1 : -1;
  }
};

int main(){
  Solution s;
  vector<int> numerators = {1, 1};
  vector<int> denominators = {6, 214748364};
  for (int i = 0; i < numerators.size(); ++i){
    cout << s.fractionToDecimal(numerators[i], denominators[i]) << endl;
  }
  return 0;
}
