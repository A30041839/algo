#include "leetcode.h"

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    return longestPalindrome1(s);
  }

  string longestPalindrome1(string s){
    int len = s.length();
    int k, i, j, begin, maxlen = 0;
    for (k = 0; k < len;){
      i = j = k;
      while (i >= 0 and s[i] == s[k]){
        i--;
      }
      while (j < len and s[j] == s[k]){
        j++;
      }
      k = j;
      while (i >= 0 and j < len and s[i] == s[j]){
        i--;
        j++;
      }
      if (j - i - 1 > maxlen){
        maxlen = j - i - 1;
        begin = i + 1;
      }
    }
    return s.substr(begin, maxlen);
  }

};

int main(){
  Solution s;
  cout << s.longestPalindrome("abba") << endl;
  return 0;
}
