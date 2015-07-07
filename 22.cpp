#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string str;
    dfs(res, str, n, 0, 0);
    return res;
  }

  void dfs(vector<string>& res, string& str, int n, int left, int unpair){
    if (str.size() == 2 * n) {
      res.push_back(str);
      return;
    }
    if (left < n) {
      str.push_back('(');
      dfs(res, str, n, left + 1, unpair + 1);
      str.pop_back();
    }
    if (unpair > 0) {
      str.push_back(')');
      dfs(res, str, n, left, unpair - 1);
      str.pop_back();
    }
  }
};

int main(){
  Solution s;
  vector<string> res = s.generateParenthesis(3);
  for (string str : res){
    cout << str << endl;
  }
  return 0;
}
