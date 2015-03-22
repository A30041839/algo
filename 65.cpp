#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isNumber(string s) {
    vector<string> vec;
    istringstream iss(s);
    string tmp;
    while (iss >> tmp) {
      vec.push_back(tmp);
    }
    if (vec.size() > 1 or vec.size() == 0) {
      return false;
    }
    string num = vec[0];
    int flag_e = 0;
    int flag_dot = 0;
    int flag_num = 0;
    for (int i = 0; i < num.size(); ++i) {
      char c = num[i];
      if ((c == '+' or c == '-') and i != num.size() - 1) {
        if (i != 0 and num[i - 1] != 'e') {
          return false;
        }
      }else if (c == 'e' and i != 0 and i != num.size() - 1) {
        if (flag_e == 0 and flag_num == 1) {
          flag_e = 1;
          flag_num = 0;
        }else {
          return false;
        }
      }else if (c == '.') {
        if (flag_dot == 0 and flag_e == 0) {
          flag_dot = 1;
        }else {
          return false;
        }
      }else if (c >= '0' and c <= '9') {
        flag_num = 1;
        continue;
      }else {
        return false;
      }
    }
    if (flag_num == 0) {
      return false;
    }
    return true;
  }
};

int main(){
  Solution s;
  vector<string> nums = {"0.", " 0.1.1 ", " -2.3", "-2e10", "+5e17.2"};
  for (string num : nums) {
    if (s.isNumber(num)) {
      cout << num << " is a number" << endl;
    }else {
      cout << num << " is not a number" << endl;
    }
  }
  return 0;
}
