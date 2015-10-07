#include "leetcode.h"

using namespace std;

class Solution {
private:
  vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> res;
    solve(res, "", digits, 0);
    return res;
  }

  void solve(vector<string>& res, string cur, string digits, int dep) {
    if (dep == digits.size()) {
      res.push_back(cur);
      return;
    }
    for (char c : map[digits[dep] - '0']) {
      cur.push_back(c);
      solve(res, cur, digits, dep + 1);
      cur.pop_back();
    }
  }
};

int main(){
  Solution s;
  vector<string> res = s.letterCombinations("23");
  for (string str : res){
    cout << str << ",";
  }
  cout << endl;
  return 0;
}
