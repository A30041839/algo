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
  bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.empty()) {
      return false;
    }
    vector<int> possible(s.length(), 0);
    for (int i = 0; i < s.length(); ++i) {
      if (dict.count(s.substr(0, i + 1)) > 0) {
        possible[i] = 1;
      }else {
        for (int k = 0; k < i; ++k) {
          if (possible[k] == 1 and dict.count(s.substr(k + 1, i - k)) > 0) {
            possible[i] = 1;
            break;
          }
        }
      }
      possible[i] = possible[i] == 1 ? 1 : 0;
    }
    return possible[s.length() - 1] == 1 ? true : false;
  }
};

int main(){
  Solution s;
  string str("leetcode");
  unordered_set<string> dict = {"leet", "code"};
  if (s.wordBreak(str, dict)){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return 0;
}
