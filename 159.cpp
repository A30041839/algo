#include "leetcode.h"

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    return lengthOfLongestSubstringTwoDistinct3(s);
  }

  int lengthOfLongestSubstringTwoDistinct1(string s) {
    unordered_set<char> st;
    int n = s.size(), res = 0, i, j, beg;
    for (i = 0, beg = 0; i < n; ++i) {
      st.insert(s[i]);
      if (st.size() > 2) {
        for (j = i - 2; j >= beg; --j) {
          if (s[j] != s[i - 1]) {
            break;
          }
        }
        st.erase(s[j]);
        beg = j + 1;
      }
      res = max(res, i - beg + 1);
    }
    return res;
  }

  //no backing
  int lengthOfLongestSubstringTwoDistinct2(string s) {
    unordered_set<char> st;
    int n = s.size(), res = 0, i, j, beg;
    for (i = 0, beg = 0; i < n; ++i) {
      st.insert(s[i]);
      if (st.size() > 2) {
        st.erase(s[j - 1]);
        beg = j;
      }
      if (i > 0 and s[i] != s[i - 1]) {
        j = i;
      }
      res = max(res, i - beg + 1);
    }
    return res;
  }

  int lengthOfLongestSubstringTwoDistinct3(string s) {
    vector<bool> hash(256, false);
    int n = s.size(), res = 0, counter = 0, i, j, beg;
    for (i = 0, beg = 0; i < n; ++i) {
      if (hash[s[i]] == false) {
        hash[s[i]] = true;
        counter++;
      }
      if (counter > 2) {
        hash[s[j - 1]] = false;
        beg = j;
        counter--;
      }
      if (i > 0 and s[i] != s[i - 1]) {
        j = i;
      }
      res = max(res, i - beg + 1);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<string> strs = {"aaaa", "ab", "abbb", "afffxxx", "afffuuuu"};
  for (auto str : strs) {
    cout << str << ":" << s.lengthOfLongestSubstringTwoDistinct(str) << endl;
  }
  return 0;
}
