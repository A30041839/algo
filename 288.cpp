#include "leetcode.h"

using namespace std;

class ValidWordAbbr {
  string getAbbr(string word) {
    if (word.size() <= 2) {
      return word;
    }else {
      return word.front() + to_string(word.size() - 2) + word.back();
    }
  }

  unordered_map<string, vector<string>> dictAbbr;

public:
  ValidWordAbbr(vector<string> &dictionary) {
    for (string& word : dictionary) {
      dictAbbr[getAbbr(word)].push_back(word);
    }
  }

  bool isUnique(string word) {
    string tmp = getAbbr(word);
    for (auto it = dictAbbr[tmp].begin(); it != dictAbbr[tmp].end(); ++it) {
      if (*it != word) {
        return false;
      }
    }
    return true;
  }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
