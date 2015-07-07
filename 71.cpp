#include "leetcode.h"

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string res, str;
    istringstream iss(path);
    vector<string> v;
    while (getline(iss, str, '/')) {
      if (!str.empty()) {
        if (str == "..") {
          if (!v.empty()) {
            v.pop_back();
          }
        }else if (str != ".") {
          v.push_back(str);
        }
      }
    }
    for (int i = 0; i < v.size(); ++i) {
      res.append("/" + v[i]);
    }
    if (v.empty()) {
      res.push_back('/');
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.simplifyPath("/a/./b/../../c/") << endl;
  return 0;
}
