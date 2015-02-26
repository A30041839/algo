#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    unordered_map<string, int> dic;
    int len = L[0].length(), cnt = L.size();
    for (string word : L){
      dic[word]++;
    }
    vector<int> res;
    for (int i = 0; i <= (int)S.length() - cnt * len; i++){
      unordered_map<string, int> tmp;
      int k;
      for (k = 0; k < cnt; ++k){
        string str = S.substr(k * len + i, len);
        if (dic.count(str) > 0 and tmp[str] < dic[str]){
          tmp[str]++;
        }else{
          break;
        }
      }
      if (k == cnt){
        res.push_back(i);
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  string str("aaa");
  vector<string> L = {"a","a"};
  vector<int> res = s.findSubstring(str, L);
  for (int i = 0; i < res.size(); ++i){
    cout << res[i] << ",";
  }
  cout << endl;
  return 0;
}
