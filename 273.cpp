#include "leetcode.h"

using namespace std;

class Solution {
private:
  vector<string> ones = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                         "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                         "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                         "Eighty", "Ninety"};
  vector<string> bigs = {"Hundred", "Thousand", "Million", "Billion"};
public:
  string numberToWords(int num) {
    if (num < 20) {
      return ones[num];
    }else if (num < 100) {
      return tens[num / 10] + (num % 10 ? " " + numberToWords(num % 10) : "");
    }else if (num < 1000) {
      return numberToWords(num / 100) + " " + bigs[0] + (num % 100 ? " " + numberToWords(num % 100) : "");
    }else if (num < pow(10, 6)) {
      return numberToWords(num / 1000) + " " + bigs[1] + (num % 1000 ? " " + numberToWords(num % 1000) : "");
    }else if (num < pow(10, 9)) {
      return numberToWords(num / pow(10, 6)) + " " + bigs[2] + (num % (int)pow(10, 6) ? " " + numberToWords(num % (int)pow(10, 6)) : "");
    }else {
      return numberToWords(num / pow(10, 9)) + " " + bigs[3] + (num % (int)pow(10, 9) ? " " + numberToWords(num % (int)pow(10, 9)) : "");
    }
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 12, 123, 1234, 56789, 90232342};
  for (auto x : v) {
    cout << s.numberToWords(x) << endl;
  }
  return 0;
}
