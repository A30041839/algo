#include "leetcode.h"

using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string res;
    while (n) {
      n--;
      res.push_back(n % 26 + 'A');
      n /= 26;
    }
    reverse(res.begin(), res.end());
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
