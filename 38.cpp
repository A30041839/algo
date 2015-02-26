#include "leetcode.h"

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    if (n < 1){
      return "";
    }else{
      return countAndSay1(n);
    }
  }

  string countAndSay1(int n){
    string str = "1";
    while (--n){
      string tmp;
      int cnt = 1;
      char c = str[0];
      for (int i = 1; i < str.length(); ++i){
        if (str[i] == str[i - 1]){
          cnt++;
        }else{
          tmp.push_back(cnt + '0');
          tmp.push_back(c);
          c = str[i];
          cnt = 1;
        }
      }
      tmp.push_back(cnt + '0');
      tmp.push_back(c);
      str = tmp;
    }
    return str;
  }
};

int main(){
  Solution s;
  cout << s.countAndSay(20) << endl;
  return 0;
}
