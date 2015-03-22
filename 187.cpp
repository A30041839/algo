#include "leetcode.h"

using namespace std;

/*encode
 * A:00
 * T:01
 * G:10
 * C:11
 */
class Solution {
public:
  static unordered_map<char, int> codemap;

  vector<string> findRepeatedDnaSequences(string s) {
    return findRepeatedDnaSequences1(s);
  }

  vector<string> findRepeatedDnaSequences1(string s) {
    if (s.size() <= 10) {
      return {};
    }
    int code = 0;
    int mask = 0x000FFFFF;
    vector<string> res;
    unordered_map<int, int> cnt;
    for (int i = 0; i < s.size(); ++i) {
      code <<= 2;
      code |= codemap[s[i]];
      code &= mask;
      if (i >= 9) {
        cnt[code]++;
        if (cnt[code] == 2) {
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
