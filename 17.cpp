#include "leetcode.h"

using namespace std;

class Solution {
private:
  static vector<string> map;

  vector<string> dfs1(string digits){
    vector<string> res;
    if (digits.empty()) {
      return {{}};
    }
    vector<string> res1 = dfs1(digits.substr(1));
    for (char c : map[digits[0] - '0']) {
      for (string str : res1) {
        res.push_back(c + str);
      }
    }
    return res;
  }

  void dfs2(string digits, vector<string>& res, string str) {
    if (digits.empty()){
      res.push_back(str);
      return;
    }
    string mapped_letters = map[digits[0] - '0'];
    for (char c : mapped_letters){
      dfs2(digits.substr(1), res, str + c);
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    vector<string> res;
    dfs2(digits, res, "");
    return res;
  }
};

vector<string> Solution::map = {"", "", "abc", "def", "ghi", "jkl", "mno",
  "pqrs", "tuv", "wxyz"};

int main(){
  Solution s;
  vector<string> res = s.letterCombinations("23");
  for (string str : res){
    cout << str << ",";
  }
  cout << endl;
  return 0;
}
