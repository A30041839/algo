#include "leetcode.h"

using namespace std;

class Solution {
public:
  int compareVersion(string version1, string version2) {
    istringstream iss1(version1);
    istringstream iss2(version2);
    string str1, str2;
    char delim = '.';
    while (true){
      auto& is1 = getline(iss1, str1, delim);
      auto& is2 = getline(iss2, str2, delim);
      if (is1 or is2){
        if (!is1 and atoi(str2.c_str()) != 0){
          return -1;
        }else if(!is2 and atoi(str1.c_str()) != 0 ){
          return 1;
        }else if(is1 and is2){
          int a = atoi(str1.c_str());
          int b = atoi(str2.c_str());
          if (a > b){
            return 1;
          }else if (a < b){
            return -1;
          }
        }
      }else{
        break;
      }
    }
    return 0;
  }
};


int main(){
  string v1("1.0");
  string v2("1");
  string v3("2.1");
  string v4("2.1.1");
  Solution s;
  if (s.compareVersion(v1, v2) == 1){
    cout << v1 << ">" << v2 << endl;
  }else if (s.compareVersion(v1, v2) == -1){
    cout << v1 << "<" << v2 << endl;
  }else{
    cout << v1 << "=" << v2 << endl;
  }
  return 0;
}
