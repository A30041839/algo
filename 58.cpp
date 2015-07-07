#include "leetcode.h"

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    return lengthOfLastWord3(s);
  }

  int lengthOfLastWord1(string s) {
    istringstream iss(s);
    string str;
    while (iss >> str) {}
    return str.size();
  }

  int lengthOfLastWord2(string s) {
    int res = 0;
    while (s.back() == ' ') {
      s.pop_back();
    }
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == ' ') {
        res = n - 1 - i;
        break;
      }else if (i == 0) {
        res = n;
      }
    }
    return res;
  }

  int lengthOfLastWord3(string s) {
    int res = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] != ' '){
        res++;
      }else if (res > 0) {
        break;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  string str = "Hello Worlds   ";
  cout << s.lengthOfLastWord(str) << endl;
  return 0;
}
