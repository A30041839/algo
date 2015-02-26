#include "leetcode.h"

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0){
      return "";
    }
    string res = strs[0];
    for (int i = 1; i < strs.size(); ++i){
      string tmp = "";
      for (int k = 0; k < strs[i].length() and k < res.length(); ++k){
        if (strs[i][k] == res[k]){
          tmp += res[k];
        }else{
          break;
        }
      }
      res = tmp;
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
