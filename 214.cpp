#include "leetcode.h"

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    return shortestPalindrome1(s);
  }

  //http://www.cnblogs.com/grandyang/p/4523624.html
  //kmp
  string shortestPalindrome1(string s) {
  }
};

int main() {
  Solution s;
  vector<string> v = {"aacecaaa", "abcd", "xaxx", "adcba", "cdcba", "ccba"};
  for (auto str : v) {
    cout << s.shortestPalindrome(str) << endl;
  }
  return 0;
}
