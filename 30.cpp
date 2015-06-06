#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    return findSubstring2(s, words);
  }

  //naive method O(n * word_cnt * word_len)
  vector<int> findSubstring1(string s, vector<string>& words) {
    int word_len = words[0].size(), word_cnt = words.size(), n = s.size();
    vector<int> res;
    unordered_map<string, int> dic;
    for (auto& word : words) {
      dic[word]++;
    }
    for (int i = 0; i <= n - word_len * word_cnt; ++i) {
      unordered_map<string, int> mp;
      bool f = true;
      for (int k = 0; k < word_cnt; k++) {
        string str = s.substr(i + k * word_len, word_len);
        if (dic.count(str) and mp[str] < dic[str]) {
          mp[str]++;
        }else {
          f = false;
          break;
        }
      }
      if (f) {
        res.push_back(i);
      }
    }
    return res;
  }

  //slide window: O(n * word_len)
  vector<int> findSubstring2(string s, vector<string>& words) {
    int n = s.size(), word_len = words[0].size();
    int i = 0, counter = 0, window_beg, window_end, word_cnt = words.size();
    unordered_map<string ,int> dic;
    unordered_map<string, int> mp;
    vector<int> res;
    for (string& word : words) {
      dic[word]++;
    }
    while (i < word_len) {
      window_beg = i;
      counter = 0;
      mp.clear();
      for (window_end = i; window_end <= n - word_len; window_end += word_len) {
        string str = s.substr(window_end, word_len);
        if (dic.find(str) != dic.end()) {
          if (mp[str] < dic[str]) {
            mp[str]++;
            counter++;
          }else {
            //set windows begin to the end of first occurence of current word
            while (s.substr(window_beg, word_len) != str) {
              mp[s.substr(window_beg, word_len)]--;
              counter--;
              window_beg += word_len;
            }
            window_beg += word_len;
          }
        } else {
          mp.clear();
          counter = 0;
          window_beg = window_end + word_len;
        }
        if (counter == word_cnt) {
          res.push_back(window_beg);
        }
      }
      i++;
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
