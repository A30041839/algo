#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    if (s.empty() or dict.empty()) {
      return {};
    }
    vector<int> possible(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
      if (dict.count(s.substr(0, i + 1)) > 0) {
        possible[i] = 1;
      }else{
        for (int k = 0; k < i; ++k)  {
          if (possible[k] == 1 and dict.count(s.substr(k + 1, i - k)) > 0) {
            possible[i] = 1;
            break;
          }
        }
      }
    }
    vector<string> res;
    string sentence;
    if (possible[s.size() - 1] == 0) {
      return res;
    }
    getSentence(0, s, possible, res, sentence, dict);
    return res;
  }

  void getSentence(int start, string& s, vector<int>& possible, vector<string>& res,
                   string& sentence, unordered_set<string>& dict) {
    if (start == s.size()) {
      res.push_back(sentence.substr(0, sentence.size() - 1));
      return;
    }
    for (int i = start; i < s.size(); ++i) {
      if (dict.count(s.substr(start, i - start + 1)) > 0 and possible[i] == 1) {
        sentence.append(s.substr(start, i - start + 1)).append(" ");
        getSentence(i + 1, s, possible, res, sentence, dict);
        sentence.resize(sentence.size() - i + start - 2);
      }
    }
  }

};

int main(){
  Solution s;
  unordered_set<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
  vector<string> res = s.wordBreak(str, dict);
  for (string& sen : res) {
    cout << sen << endl;
  }
  return 0;
}
