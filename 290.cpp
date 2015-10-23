#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, string> mp;
    unordered_set<string> st;
    int n = pattern.size();
    istringstream iss(str);
    string word;
    int i = 0;
    while (i < n and iss >> word) {
      if (mp.count(pattern[i])) {
        if (word != mp[pattern[i]]) {
          return false;
        }
      }else {
        mp[pattern[i]] = word;
        if (st.count(word)) {
          return false;
        }
        st.insert(word);
      }
      i++;
    }
    if (!iss.eof() or i < n) {
      return false;
    }else {
      return true;
    }
  }
};
