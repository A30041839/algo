#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n <= 0){
      return res;
    }
    string str;
    _generateParenthesis(res, str, 0, 0, n);
    return res;
  }

  void _generateParenthesis(vector<string>& res, string& str, int left, int unmatch_left, int n){
    if (str.length() == 2 * n){
      res.push_back(str);
      return;
    }
    if (unmatch_left > 0){
      str.push_back(')');
      _generateParenthesis(res, str, left, unmatch_left - 1, n);
      str.pop_back();
    }
    if (left < n){
      str.push_back('(');
      _generateParenthesis(res, str, left + 1, unmatch_left + 1, n);
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
