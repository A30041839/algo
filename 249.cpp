#include "leetcode.h"

using namespace std;

class Solution {
  string shift(string str) {
    int n = str.size();
    string res;
    for (int i = 0; i < n; ++i) {
      res.push_back((str[i] - 'a' + 1) % 26 + 'a');
    }
    return res;
  }

public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    return groupStrings1(strings);
  }

  vector<vector<string>> groupStrings1(vector<string>& strings) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;
    int n = strings.size();
    for (int i = 0; i < n; ++i) {
      string str = strings[i];
      int diff = str[0] - 'a';
      for (int j = 0; j < str.size(); ++j) {
        if (str[j] - diff >= 'a') {
          str[j] = str[j] - diff;
        }else {
          str[j] = str[j] - diff  + 26 ;
        }
      }
      mp[str].push_back(strings[i]);
    }
    for (auto& p : mp) {
      sort(p.second.begin(), p.second.end());
      res.push_back(p.second);
    }
    return res;
  }

  vector<vector<string>> groupStrings2(vector<string>& strings) {
    map<string, int> mp;
    vector<vector<string>> res;
    for (auto& str : strings) {
      mp[str]++;
    }
    for (auto& p : mp) {
      vector<string> tmp;
      string str = p.first;
      tmp.insert(tmp.begin(), p.second, str);
      string begin = str;
      str = shift(str);
      while (begin != str) {
        if (mp.find(str) != mp.end()) {
          tmp.insert(tmp.end(), mp[str], str);
          mp.erase(str);
        }
        str = shift(str);
      }
      res.push_back(tmp);
    }
    return res;
  }
};
