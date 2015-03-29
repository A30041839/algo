#include "leetcode.h"

using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string res = ""; 
    while (n-- > 0){
      int k = n % 26;
      res = (char)(k + 65) + res;
      n /= 26;
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.convertToTitle(1) << endl;
  cout << s.convertToTitle(2) << endl;
  cout << s.convertToTitle(26) << endl;
  cout << s.convertToTitle(52) << endl;
  cout << s.convertToTitle(100) << endl;
  cout << s.convertToTitle(223128) << endl;
  return 0;
}
