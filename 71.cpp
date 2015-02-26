#include "leetcode.h"

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> v;
    istringstream iss(path);
    string str;
    char delim = '/';
    while (getline(iss, str, delim)){
      if (!str.empty()){
        if (str == ".."){
          if (!v.empty()){
            v.pop_back();
          }
        }else if (str != "."){
          v.push_back(str);
        }
      }
    }
    string res;
    for (int i = 0; i < v.size(); ++i){
      res.push_back('/');
      res.append(v[i]);
    }
    if (v.size() == 0){
      res.push_back('/');
    }
    return res;
  }
};

int main(){
  Solution s;
  cout << s.simplifyPath("/../") << endl;
  return 0;
}
