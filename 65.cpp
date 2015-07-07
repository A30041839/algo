#include "leetcode.h"

using namespace std;

class Solution {
private:
  bool isNumber1helper(string str, bool eflag) {
    bool dot = false, sgn = false, num = false;;
    int n = str.size();
    for (int i = 0; i < n; ++i) {
      if (str[i] == '+' or str[i] == '-') {
        if (sgn) { //sign has appeared more than once
          return false;
        }else {
          if (i != 0) {
            return false; //sgn not appearing at front
          }else {
            sgn = true;
          }
        }
      }else if (str[i] == '.') {
        if (dot) { //dot has appeared more than once
          return false;
        }else {
          dot = true;
        }
      }else if (isdigit(str[i])) {
        num = true;
      }else {
        return false;
      }
    }
    if (eflag) {
      return num and !dot;
    }else {
      return num;
    }
  }

public:
  bool isNumber(string s) {
    return isNumber1(s);
  }

  bool isNumber1(string s) {
    int k = 0;
    istringstream iss(s);
    string str;
    while (iss >> str) {
      k++;
    }
    if (str.empty() or k > 1) {
      return false;//containing one separate space
    }
    size_t pos = str.find('e');
    if (pos == string::npos) {
      return isNumber1helper(str, false);
    }else {
      return isNumber1helper(str.substr(0, pos), false)
        and isNumber1helper(str.substr(pos + 1), true);
    }
  }
};

int main(){
  Solution s;
  vector<string> nums = {"e", "6e6.5", " 0.1.1 ", " -2.3", "-2 e10", "+5e17.2"};
  for (string num : nums) {
    if (s.isNumber(num)) {
      cout << num << " is a number" << endl;
    }else {
      cout << num << " is not a number" << endl;
    }
  }
  return 0;
}
