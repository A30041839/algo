#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<string> > partition(string s) {
    vector<string> v;
    return partition1(s, v);
  }

  vector<vector<string> > partition1(string s, vector<string>& v){
    if (s.empty()){
      return {v};
    }
    vector<vector<string> > res;
    int k = s.size();
    for (int i = 0; i < k; i++){
      string str = s.substr(0, i + 1);
      if (checkPalindrome(str)){
        v.push_back(str);
        for (auto& v1 : partition1(s.substr(i + 1), v)){
          res.push_back(v1);
        }
        v.pop_back();
      }
    }
    return res;
  }

  bool checkPalindrome(string s){
    int i = 0, j = s.size() - 1;
    while (i < j){
      if (s[i++] != s[j--]){
        return false;
      }
    }
    return true;
  }
};

int main(){
  Solution s;
  string str("abaaba");
  vector<vector<string> > res = s.partition(str);
  for (auto& v : res){
    for (auto& tmp : v){
      cout << tmp << ",";
    }
    cout << endl;
  }
  return 0;
}
