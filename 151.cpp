#include "leetcode.h"

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    reverseWords2(s);
  }

  //O(n) space
  void reverseWords1(string &s) {
    vector<string> words;
    istringstream iss(s);
    ostringstream oss;
    string str;
    while (iss >> str) {
      words.push_back(str);
    }
    for (int i = words.size() - 1; i >= 0; --i) {
      oss << words[i];
      if (i > 0) {
        oss << " ";
      }
    }
    s = oss.str();
  }

  void reverseWords2(string &s) {
    string res;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] != ' ') {
        int j = i - 1;
        while (j >= 0 and s[j] != ' ') {
          j--;
        }
        res.append(s.begin() + j + 1, s.begin() + i + 1);
        res.push_back(' ');
        i = j;
      }
    }
    if (!res.empty()) {
      res.pop_back();
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
