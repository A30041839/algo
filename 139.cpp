#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.empty()){
      return false;
    }
    return wordBreak1(s, dict);
  }

  bool wordBreak1(string s, unordered_set<string>& dict) {
    if (s.empty()){
      return true;
    }
    for (int i = 1; i <= s.length(); ++i){
      if (dict.count(s.substr(0, i)) != 0){
        if (wordBreak1(s.substr(i), dict)){
          return true;
        }
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  string str("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
  unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  if (s.wordBreak(str, dict)){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return 0;
}
