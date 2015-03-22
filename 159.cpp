#include "leetcode.h"

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    return lengthOfLongestSubstringTwoDistinct1(s);
  }

  int lengthOfLongestSubstringTwoDistinct1(string s) {
    unordered_set<char> uset;
    int start = 0, max_len = 0;
    for (int i = 0; i < s.size(); ++i) {
      uset.insert(s[i]);
      if (uset.size() > 2) {
        max_len = max(max_len, i - start);
        int j = i - 2;
        while (s[j] == s[i - 1]) {
          j--;
        }
        start = j + 1;
        uset.clear();
        uset.insert(s[i]);
        uset.insert(s[i - 1]);
      }else {
        max_len = max(max_len, i - start + 1);
      }
    }
    return max_len;
  }
};

int main(){
  Solution s;
  string str = "abbbbtffff";
  cout << s.lengthOfLongestSubstringTwoDistinct(str) << endl;
  return 0;
}
