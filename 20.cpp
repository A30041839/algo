#include "leetcode.h"

using namespace std;

class Solution {
public:
  static map<char, char> mp;

  bool isValid(string s) {
    return isValid1(s);
  }

  bool isValid1(string s) {
    vector<char> v;
    int n = s.size();
    for (int i = 0; i < n; ++i){
      if (mp.find(s[i]) == mp.end()) {
        v.push_back(s[i]);
      }else {
        if (v.empty() or v.back() != mp[s[i]]) {
          return false;
        }
        v.pop_back();
      }
    }
    return v.empty();
  }
};

map<char, char> Solution::mp = {{'}', '{'}, {')', '('}, {']', '['}};

int main(){
  Solution s;
  vector<string> vec = {"(", ")", "()", "(]", "((])", "[{}(())]", "())"};
  for (string str : vec){
    if (s.isValid(str)){
      cout << str << " is valid" << endl;
    }else{
      cout << str << " is not valid" << endl;
    }
  }
  return 0;
}
