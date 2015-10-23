#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    return isInterleave1(s1, s2, s3);
  }

  bool isInterleave1(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    unordered_map<int, int> mp;
    unordered_map<int, int> tmp;
    mp.insert({-1, -1});
    int k = 0;
    int n = s3.size();
    while (!mp.empty() and k < n) {
      tmp.clear();
      for (auto& p : mp) {
        if (s1[p.first + 1] == s3[k]) {
          tmp.insert({p.first + 1, p.second});
        }
        if (s2[p.second + 1] == s3[k]) {
          tmp.insert({p.first, p.second + 1});
        }
      }
      k++;
      mp = tmp;
    }
    return !mp.empty();
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
