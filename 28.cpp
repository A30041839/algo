#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution1 {
public:
  int strStr(char *haystack, char *needle) {
    if (haystack == 0 or needle == 0){
      return -1;
    }
    if (needle[0] == 0){
      return 0;
    }
    if (haystack[0] == 0){
      return -1;
    }

    int h_len = strlen(haystack);
    int n_len = strlen(needle);
    vector<int> p(n_len, 0);
    init(p, needle, n_len);
    int j = -1;
    for (int i = 0; i < h_len; ++i){
      while (j >= 0 and needle[j + 1] != haystack[i]){
        j = p[j];
      }
      if (needle[j + 1] == haystack[i]){
        j++;
      }
      if (j == n_len - 1){
        return i - j;
      }
    }
    return -1;
  }

  void init(vector<int>& p, char* needle, int n_len) {
    int j = -1;
    p[0] = -1;
    for (int i = 1; i < n_len; ++i){
      while (j >= 0 and needle[j + 1] != needle[i]){
        j = p[j];
      }
      if (needle[j + 1] == needle[i]){
        j++;
      }
      p[i] = j;
    }
  }
};

class Solution {
public:
  int strStr(char *haystack, char *needle) {
    if (haystack == 0 or needle == 0){
      return -1;
    }
    if (needle[0] == 0){
      return 0;
    }
    if (haystack[0] == 0){
      return -1;
    }

    int i = 0;
    int j = 0;
    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    while (i < l1 - l2 + 1){
      int k = i;
      while (j < l2 and haystack[k] == needle[j]){
        k++;
        j++;
      }
      if (j == l2){
        return i;
      }
      i++;
      j = 0;
    }
    return -1;
  }
};

int main(){
  Solution s;
  char* s1 = "atestingwithconfidencetesting";
  char* s2 = "testing";
  char* s3 = "confidence";
  char* s4 = "hello";
  char* s5 = "";
  cout << s.strStr(s1, s2) << endl;
  cout << s.strStr(s1, s3) << endl;
  cout << s.strStr(s1, s4) << endl;
  cout << s.strStr(s1, s5) << endl;
  return 0;
}
