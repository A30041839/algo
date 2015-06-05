#include "leetcode.h"

using namespace std;

class Solution {
public:
  static unordered_map<char, int> codemap;

  vector<string> findRepeatedDnaSequences(string s) {
    return findRepeatedDnaSequences1(s);
  }

  vector<string> findRepeatedDnaSequences1(string s) {
    int n = s.size();
    if (n <= 10) {
      return {};
    }
    vector<string> res;
    unordered_map<int, int> cnt;
    int mask = 0x000FFFFF, code = 0;
    for (int i = 0; i < n; ++i) {
      code <<= 2;
      code = (code | codemap[s[i]]) & mask;
      if (i >= 9) {
        if (++cnt[code] == 2) {
          res.push_back(s.substr(i - 9, 10));
        }
      }
    }
    return res;
  }
};

unordered_map<char, int> Solution::codemap = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};

int main(){
  Solution s;
  string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> res = s.findRepeatedDnaSequences(str);
  for (string& a : res){
    cout << a << ",";
  }
  cout << endl;
  return 0;
}
