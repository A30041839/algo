#include <iostream>
#include <math.h>
#include <ctype.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    bool res = true;
    int i = 0;
    int j = s.length() - 1;
    while (i < j){
      while (!((s[i] >= '0' and s[i] <= '9') or (s[i] >= 65 and s[i] <= 90) or (s[i] >= 97 and s[i] <= 122)) and i < j){
        ++i;
      }
      while (!((s[j] >= '0' and s[j] <= '9') or (s[j] >= 65 and s[j] <= 90) or (s[j] >= 97 and s[j] <= 122)) and i < j){
        --j;
      }
      if (!((s[i] == s[j]) or (s[i] > '9' and s[j] > '9' and abs(s[i] - s[j]) == 32))){
        res = false;
        break;
      }else{
        ++i;
        --j;
      }
    }
    return res;
  }
};

int main(){
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "race a car";
  Solution s;
  if (s.isPalindrome(s1)){
    cout << "yes";
  }else{
    cout << "no";
  }
  return 0;
}
