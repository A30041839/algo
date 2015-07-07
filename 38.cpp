#include "leetcode.h"

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string str("1");
    while (--n) {
      ostringstream oss;
      int k = str.size(), cnt = 1;
      for (int i = 1; i <= k; ++i) {
        if (i == k or str[i] != str[i - 1]) {
          oss << cnt << str[i - 1];
          cnt = 1;
        }else {
          cnt++;
        }
      }
      str = oss.str();
    }
    return str;
  }
};

int main(){
  Solution s;
  cout << s.countAndSay(5) << endl;
  cout << s.countAndSay(20) << endl;
  return 0;
}
