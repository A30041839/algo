#include "leetcode.h"

using namespace std;

class Solution {
public:
  int atoi(const char *str) {
    istringstream iss(str);
    string strn;
    iss >> strn;
    int sgn = 1;
    int res = 0;
    for (int i = 0; i < strn.length(); ++i){
      char c = strn[i];
      if (c >= '0' and c <= '9'){
        if (res <= INT_MAX / 10 and res >= INT_MIN / 10){
          res *= 10;
        }else{
          return res > 0 ? INT_MAX : INT_MIN;
        }
        if (res >= 0){
          if(res <= INT_MAX - c + '0'){
            res += c - '0';
          }else{
            return INT_MAX;
          }
        }else if (res < 0){
          if (res >= INT_MIN + c - '0'){
            res -= c - '0';
          }else{
            return INT_MIN;
          }
        }
        if (c != '0' and sgn == -1){
          res *= -1;
          sgn = 1;
        }
      }else if (c == '-'){
        if (i != 0){
          return 0;
        }
        sgn = -1;
      }else if (c == '+'){
        if (i != 0){
          return 0;
        }
        sgn = 1;
      }else if (res != 0){
        break;
      }else{
        return 0;
      }
    }
    return res;
  }
};

int main(){
  const char *n1 = "-12147483648";
  const char *n2 = " -0012a42";
  const char *n3 = " ++123";
  const char *n4 = "-123";
  const char *n5 = " +123 ";
  const char *n6 = "-123";
  const char *n7 = " -123";
  const char *n8 = "123456792383434";
  const char *n9 = "0123";

  Solution s;
  vector<const char*> vec = {n1, n2, n3, n4, n5, n6, n7, n8, n9}; 
  for (auto n : vec){
    cout << atoi(n) << "," << s.atoi(n) << endl;
  }
  return 0;
}
