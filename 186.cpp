#include "leetcode.h"

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    for (int start = 0, i = 0; i < s.length(); ++i) {
      if (s[i] == ' ') {
        reverse(s.begin() + start, s.begin() + i);
        start = i + 1;
      }
      if (i == s.length() - 1){
        reverse(s.begin() + start, s.end());
      }
    }
  }
};

int main(){
  Solution s;
  string str = "";
  s.reverseWords(str);
  cout << str << endl;

  return 0;
}
