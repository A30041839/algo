#include "leetcode.h"

using namespace std;

class Solution {
private:
  void search(string&s, int p, int q, int n, int& maxlen, int&start) {
    while (p >= 0 and q < n and s[p] == s[q]) {
      p--;
      q++;
    }
    if (q - p - 1 > maxlen) {
      maxlen = q - p - 1;
      start = p + 1;
    }
  }

public:
  string longestPalindrome(string s) {
    return longestPalindrome3(s);
  }

  //O(n^2) time
  string longestPalindrome1(string s){
    int n = s.size(), maxlen = 0;
    int k = 0, i, j, start;
    while (k < n) {
      i = k - 1;
      j = k + 1;
      while (j < n and s[j] == s[k]) {
        j++;
      }
      k = j;
      while (i >= 0 and j < n and s[i] == s[j]) {
        i--;
        j++;
      }
      if (maxlen < j - i - 1) {
        maxlen = j - i - 1;
        start = i + 1;
      }
    }
    return s.substr(start, maxlen);
  }

  //O(n^2) time
  string longestPalindrome2(string s){
    int maxlen = 0, start, n = s.size();
    for (int i = 0; i < n - maxlen / 2; ++i) {
      if (i < n - 1 and s[i] == s[i + 1]) {
        //to deal with even-length palindromic string
        search(s, i, i + 1, n, maxlen, start);
      }
      search(s, i, i, n, maxlen, start);
    }
    return s.substr(start, maxlen);
  }

  string longestPalindrome3(string s){
  }
};

int main(){
  Solution s;
  cout << s.longestPalindrome("abba") << endl;
  return 0;
}
