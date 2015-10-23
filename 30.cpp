#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int n = s.size(), wordlen = words[0].size();
    int start = 0, wordnum = words.size();
    unordered_map<string, int> mp;
    for (auto& w : words) {
      mp[w]++;
    }
    unordered_map<string, int> cnt;
    vector<int> res;
    while (start < wordlen) {
      cnt.clear();
      int count = 0;
      for (int beg = start, i = beg; i <= n - wordlen; i += wordlen) {
        string str = s.substr(i, wordlen);
        if (mp.count(str)) {
          if (cnt[str] < mp[str]) {
            cnt[str]++;
            count++;
          }else {
            while (s.substr(beg, wordlen) != str) {
              cnt[s.substr(beg, wordlen)]--;
              count--;
              beg += wordlen;
            }
            beg += wordlen;
          }
        }else {
          cnt.clear();
          count = 0;
          beg = i + wordlen;
        }
        if (count == wordnum) {
          res.push_back(beg);
        }
      }
      start++;
    }
    return res;
  }
};

int main(){
  Solution s;
  string str("barfoothefoobarman");
  vector<string> L = {"foo","bar"};
  vector<int> res = s.findSubstring(str, L);
  for (int i = 0; i < res.size(); ++i){
    cout << res[i] << ",";
  }
  cout << endl;
  return 0;
}
