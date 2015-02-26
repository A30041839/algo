#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    return anagrams1(strs);
  }

  vector<string> anagrams1(vector<string>& strs){
    unordered_map<string, vector<string> > mp;
    vector<string> res;
    for (auto& str : strs){
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      if (mp.count(tmp) == 0){
        mp[tmp] = {};
      }
      mp[tmp].push_back(str);
    }
    for (auto& p : mp){
      if (p.second.size() > 1){
        for (auto& s : p.second){
          res.push_back(s);
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<string> strs = {"abc", "china", "usa", "inach", "cba", "sau", "google"};
  vector<string> anagrams = s.anagrams(strs);
  for (auto& anagram : anagrams){
    cout << anagram << ",";
  }
  cout << endl;
  return 0;
}
