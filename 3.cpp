#include "leetcode.h"

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    return lengthOfLongestSubstring1(s);
  }

  int lengthOfLongestSubstring1(string s){
    unordered_map<char, int> mp;
    int maxl = 0;
    s.push_back(s.back());
    int l = s.length();
    for (int i = 0, j = 0; i < l; ++i){
      if (mp.count(s[i]) > 0 and mp[s[i]] >= j){
        maxl = max(maxl, i - j);
        j = mp[s[i]] + 1;
      }
      mp[s[i]] = i;
    }
    return maxl;
  }
};

int main(){
  Solution s;
  string str1("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
  string str2("61251789");
  cout << s.lengthOfLongestSubstring(str1) << endl;
  cout << s.lengthOfLongestSubstring(str2) << endl;
  return 0;
}
