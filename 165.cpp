#include "leetcode.h"

using namespace std;

class Solution {
public:
  int compareVersion(string version1, string version2) {
    return compareVersion1(version1, version2);
  }

  int compareVersion1(string version1, string version2) {
    istringstream iss1(version1), iss2(version2);
    string s1, s2;
    char delim = '.';
    while (true) {
      auto& a = getline(iss1, s1, delim);
      auto& b = getline(iss2, s2, delim);
      int m = atoi(s1.c_str()), n = atoi(s2.c_str());
      if (!a or !b) {
        if (a) {
          return m == 0 ? 0 : 1;
        }else if (b) {
          return n == 0 ? 0 : -1;
        }else {
          return 0;
        }
      }
      if (m != n) {
        return m > n ? 1 : -1;
      }
    }
  }
};


int main(){
  string v1("1.0");
  string v2("1");
  string v3("2.1");
  string v4("2.1.1");
  Solution s;
  int res = s.compareVersion(v1, v3);
  if (res == 1){
    cout << v1 << ">" << v3 << endl;
  }else if (res == -1){
    cout << v1 << "<" << v3 << endl;
  }else{
    cout << v1 << "=" << v3 << endl;
  }
  return 0;
}
