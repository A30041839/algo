#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (i < j and !isalnum(s[i])) {
        i++;
      }
      while (i < j and !isalnum(s[j])) {
        j--;
      }
      if (tolower(s[i++]) != tolower(s[j--])) {
        return false;
      }
    }
    return true;
  }
};

int main(){
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "1a2";
  Solution s;
  if (s.isPalindrome(s2)){
    cout << "yes";
  }else{
    cout << "no";
  }
  return 0;
}
