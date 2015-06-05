#include "leetcode.h"

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    return lengthOfLongestSubstring4(s);
  }

  int lengthOfLongestSubstring1(string s){
    unordered_map<char, int> mp;
    s.push_back(s.back());
    int n = s.size(), res = 0;
    for (int cur = 0, start = 0; cur < n; ++cur) {
      if (mp.find(s[cur]) != mp.end() and mp[s[cur]] >= start) {
        res = max(res, cur - start);
        start = mp[s[cur]] + 1;
      }
      mp[s[cur]] = cur;
    }
    return res;
  }

  int lengthOfLongestSubstring2(string s){
    unordered_map<char, int> mp;
    s.push_back(s.back());
    int n = s.size(), res = 0;
    for (int i = 0, start = 0; i < n; ++i) {
      if (mp.find(s[i]) != mp.end()) {
        res = max(res, (int)mp.size());
        for (int j = mp[s[i]] - 1; j >= start; --j) {
          mp.erase(s[j]);
        }
        start = mp[s[i]] + 1;
      }
      mp[s[i]] = i;
    }
    return res;
  }

  int lengthOfLongestSubstring3(string s){
    vector<int> pos(256, -1);
    int res = 0, n = s.size(), start = 0;
    for (int i = 0; i < n; ++i) {
      start = max(start, pos[s[i]] + 1);
      pos[s[i]] = i;
      res = max(res, i - start + 1);
    }
    return res;
  }

  //similar as method 2
  int lengthOfLongestSubstring4(string s){
    int n = s.size(), res = 0, beg = 0, end = 0;
    vector<bool> visited(256, false);
    while (end < n) {
      if (!visited[s[end]]) {
        visited[s[end]] = true;
      }else {
        while (beg < end and s[beg] != s[end]) {
          visited[s[beg++]] = false;
        }
        beg++;
      }
      res = max(res, end - beg + 1);
      end++;
    }
    return res;
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
