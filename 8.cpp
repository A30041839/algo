#include "leetcode.h"

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int res = 0;
    istringstream iss(str);
    string s;
    iss >> s;
    int sgn = 1, n = s.size();
    bool overflow = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '+' or s[i] == '-') {
        if (i != 0) {
          break;
        }else {
          sgn = s[i] == '+' ? 1 : -1;
        }
      }else if (isdigit(s[i])) {
        if (res > INT_MAX / 10) {
          overflow = true;
          break;
        }
        res *= 10;
        if (res > INT_MAX - s[i] + '0') {
          overflow = true;
          break;
        }
        res += s[i] - '0';
      }else {
        break;
      }
    }
    if (overflow) {
      return sgn == 1 ? INT_MAX : INT_MIN;
    }else {
      return sgn * res;
    }
  }
};

int main(){
  string n1 = "-12147483648";
  string n2 = "    10522545459";
  string n3 = " ++123";
  string n4 = "-123";
  string n5 = " +123 ";
  string n6 = "-123 12";
  string n7 = " -123";
  string n8 = "2147483648";
  string n9 = "0123";

  Solution s;
  vector<string> vec = {n1, n2, n3, n4, n5, n6, n7, n8, n9};
  for (auto n : vec){
    cout << atoi(n.c_str()) << "," << s.myAtoi(n) << endl;
  }
  return 0;
}
