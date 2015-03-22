#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    string& longstr = s.length() > t.length() ? s: t;
    string& shortstr = s.length() < t.length() ? s : t;
    int len_long = longstr.length();
    int len_short = shortstr.length();
    if (len_long - len_short > 1) {
      return false;
    }else if (len_long - len_short == 1) {
      for (int i = 0; i < len_long; ++i) {
        if ((longstr.substr(0, i) + longstr.substr(i + 1, len_long)) == shortstr){
          return true;
        }
      }
      return false;
    }else {
      int cnt = 0;
      for (int i = 0; i < s.length(); ++i ) {
        if (s[i] != t[i]) {
          cnt++;
        }
      }
      return cnt == 1 ? true : false;
    }
  }
};

int main(){
  Solution s;
  string s1 = "ab";
  string s2 = "acb";
  if (s.isOneEditDistance(s1, s2)) {
    cout << "yes" << endl;
  }
  return 0;
}
