#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    return restoreIpAddresses2(s, 0);
  }

  void restoreIpAddresses1(vector<string>&res, string s, string ip, int dep) {
    if (dep == 4) {
      if (s.empty()) {
        ip.pop_back(); //remove trailing dot
        res.push_back(ip);
      }
      return;
    }
    string tmp;
    for (int i = 0; i < 3 and i < s.size(); ++i) {
      if (!tmp.empty() and atoi(tmp.c_str()) == 0) {
        continue;
      }
      tmp.push_back(s[i]);
      int m = atoi(tmp.c_str());
      if (m >= 0 and m <= 255) {
        restoreIpAddresses1(res, s.substr(i + 1), ip + tmp + ".", dep + 1);
      }
    }
  }

  vector<string> restoreIpAddresses2(string s, int dep) {
    vector<string> res;
    if (dep == 4) {
      if (s.empty()) {
        res.push_back("");
      }
      return res;
    }
    for (int i = 1; i <= s.size(); ++i) {
      string tmp = s.substr(0, i);
      int m = atoi(tmp.c_str());
      if ((i > 1 and tmp[0] == '0') or m > 255) {
        break;
      }
      vector<string> res1 = restoreIpAddresses2(s.substr(i), dep + 1);
      if (dep < 3) {
        tmp.push_back('.');
      }
      for (string str : res1) {
        res.push_back(tmp + str);
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  string str1 = "010010";
  string str2 = "25525511135";
  vector<string> res = s.restoreIpAddresses(str1);
  for (auto& ip : res){
    cout << ip << endl;
  }
  return 0;
}
