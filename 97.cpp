#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    return isInterleave1(s1, s2, s3);
  }

  bool isInterleave1(string s1, string s2, string s3) {
    //MLE
    if (s3.empty()) {
      if (!s1.empty() or !s2.empty()) {
        return false;
      }else {
        return true;
      }
    }

    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();
    vector<pair<int, int> > dp;
    for (int i = 0; i < l3; ++i) {
      if (i == 0) {
        if (!s1.empty() and s1[0] == s3[0]) {
          dp.push_back(make_pair(0, -1));
        }
        if (!s2.empty() and s2[0] == s3[0]) {
          dp.push_back(make_pair(-1, 0));
        }
      }else {
        if (dp.empty()) {
          return false;
        }
        vector<pair<int, int> > tmp;
        for (auto& p : dp) {
          if (p.first < l1 - 1 and s1[p.first + 1] == s3[i]) {
            tmp.push_back(make_pair(p.first + 1, p.second));
          }
          if (p.second < l2 - 1 and s2[p.second + 1] == s3[i]) {
            tmp.push_back(make_pair(p.first, p.second + 1));
          }
        }
        dp = tmp;
      }
    }
    return true;
  }
};

int main(){
  Solution s;
  string s1 = "aabcc";
  string s2 = "dbbca";
  string s3 = "aadbbcbcac";
  string s4 = "aadbbbaccc";
  string s5 = "aabcc";

  if (s.isInterleave(s1, s2, s3)) {
    cout << "yes" << endl;
  }

  return 0;
}
