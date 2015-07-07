#include "leetcode.h"

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    reverseWords1(s);
  }

  void reverseWords1(string &s) {
    reverse(s.begin(), s.end());
    s.push_back(' ');
    int n = s.size();
    for (int i = 0, j = 0; i < n; ++i) {
      if (s[i] == ' ') {
        reverse(s.begin() + j, s.begin() + i);
        j = i + 1;
      }
    }
    s.pop_back();
  }
};

int main(){
  Solution s;
  string str = "the sky is blue";
  s.reverseWords(str);
  cout << str << endl;

  return 0;
}
