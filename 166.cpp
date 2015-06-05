#include "leetcode.h"

using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    return fractionToDecimal1(numerator, denominator);
  }

  //reminder: the recurring position doesn't always start from 0
  string fractionToDecimal1(int numerator, int denominator){
    string res;
    int resSgn = sgn(numerator) * sgn(denominator);
    long numerator1 = abs((long)numerator);
    long denominator1 = abs((long)denominator);
    //generate integer part first
    res = genIntegerPart(numerator1, denominator1, resSgn);
    //if mod is not zero, generate decimal part
    if (numerator1 % denominator1) {
      res.append(genDecimalPart(numerator1 % denominator1, denominator1));
    }
    return res;
  }

private:
  int sgn(int num){
    return num >= 0 ? 1 : -1;
  }

  string genIntegerPart(long m, long n, int sgn) {
    string res;
    long i = m / n;
    do {
      res.push_back(i % 10 + '0');
      i /= 10;
    } while (i);
    if (sgn == -1 and m != 0) {
      res.push_back('-');
    }
    reverse(begin(res), end(res));
    return res;
  }

  string genDecimalPart(long m, long n) {
    string res;
    res.push_back('.');
    unordered_map<long, int> pos;
    int k = 1;
    while (m) {
      if (pos.find(m) != pos.end()) {
        res.insert(res.begin() + pos[m], '(');
        res.push_back(')');
        break;
      }else {
        pos[m] = k++;
        m *= 10;
        res.push_back('0' + m / n);
        m %= n;
      }
    }
    return res;
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
