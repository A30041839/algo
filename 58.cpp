#include "leetcode.h"

using namespace std;

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    if (s == 0 or s[0] == 0){
      return 0;
    }
    int len = 0;
    for (int i = strlen(s) - 1; i >= 0; --i){
      if (s[i] == ' '){
        if (len > 0){
          break;
        }
      }else{
        len++;
      }
    }
    return len;
  }
};

int main(){
  Solution s;
  const char* str = "World";
  cout << s.lengthOfLastWord(str) << endl;
  return 0;
}
