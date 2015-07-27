#include "leetcode.h"

using namespace std;

/* using dp:
 * possible[i] denotes whether substring s[0,i] can be segmented into dic words
 * possible[i] = true if:
 * s[0,i] is a dic word, or
 * there exists k, s.t. 0<=k<i && possible[k] = true && s[k+1,i] is a dic word
 * otherwise, possible[i] = false
 * */
class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    if (s.empty() or wordDict.empty()) {
      return false;
    }
    int n = s.size();
    vector<bool> p(n, false);
    for (int i = 0; i < n; ++i) {
      if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
        p[i] = true;
      }else {
        for (int k = i - 1; k >= 0; --k) {
          if (p[k] == true and wordDict.find(s.substr(k + 1, i - k)) != wordDict.end()) {
            p[i] = true;
            break;
          }
        }
      }
    }
    return p.back();
  }
};

int main(){
  Solution s;
  string str("leetcodes");
  unordered_set<string> dict = {"leet", "code"};
  if (s.wordBreak(str, dict)){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return 0;
}
