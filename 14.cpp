#include "leetcode.h"

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    return longestCommonPrefix1(strs);
  }

  string longestCommonPrefix1(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }
    for (int i = 0; i < strs[0].size(); ++i) {
      for (int j = 0; j < strs.size(); ++j) {
        if (strs[j].size() < i + 1 or strs[j][i] != strs[0][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }

  string longestCommonPrefix2(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }
    string res = strs[0];
    int n = strs.size(), k;
    for (int i = 1; i < n; ++i) {
      k = 0;
      while (k < res.size() and k < strs[i].size()) {
        if (res[k] != strs[i][k]) {
          break;
        }
        k++;
      }
      res.erase(res.begin() + k, res.end());
    }
    return res;
  }
};

int main(){
  string arr[2] = {"aa", "a"};
  vector<string> strs(arr, arr + 2);
  Solution s;
  cout << s.longestCommonPrefix(strs) << endl;
  return 0;
}
