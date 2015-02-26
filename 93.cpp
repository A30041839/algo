#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    unordered_set<string> dic;
    char str[3];
    for (int i = 0; i <= 255; ++i){
      sprintf(str, "%d", i);
      dic.insert(string(str));
    }
    return restoreIpAddresses1(dic, s, 1);
  }

  vector<string> restoreIpAddresses1(unordered_set<string>& dic, string s, int dep) {
    if (dep == 4){
      if (dic.count(s) > 0){
        return {s};
      }else{
        return {};
      }
    }
    vector<string> res;
    for (int i = 0; i < s.length(); ++i){
      string str1 = s.substr(0, i + 1);
      if (dic.count(str1) > 0){
        vector<string> tmp = restoreIpAddresses1(dic, s.substr(i + 1), dep + 1);
        for (auto& str2 : tmp){
          res.push_back(str1 + "." + str2);
        }
      }else{
        break;
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  string str1 = "0000";
  string str2 = "2736786374048";
  vector<string> res = s.restoreIpAddresses(str1);
  for (auto& ip : res){
    cout << ip << endl;
  }
  return 0;
}
