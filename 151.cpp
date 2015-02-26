#include "leetcode.h"

using namespace std;

class Solution1 {
public:
  void reverseWords(string &s) {
    istringstream iss(s);
    string word;
    vector<string> words;
    while (iss >> word){
      words.push_back(word);
    }
    ostringstream oss;
    for (int i = words.size() - 1; i >= 0; --i){
      oss << words[i];
      if (i != 0){
        oss << " ";
      }
    }
    s = oss.str();
  }
};

class Solution {
public:
  void reverseWords(string &s) {
    string res;
    string str;
    for (int i = s.length() - 1; i >= 0; --i){
      if (s[i] != ' '){
        if (!str.empty() and s[i + 1] == ' '){
          reverse(str.begin(), str.end());
          if (res.empty()){
            res.append(str);
          }else{
            res.push_back(' ');
            res.append(str);
          }
          str.clear();
        }
        str.push_back(s[i]);
      }
    }
    if (!str.empty()){
      reverse(str.begin(), str.end());
      if (res.empty()){
        res = str;
      }else{
        res.push_back(' ');
        res.append(str);
      }
    }
    s = res;
  }
};

int main(){
  string s = " the sky is blue  ";
  Solution sl;
  sl.reverseWords(s);
  cout << s << endl;
  return 0;
}
